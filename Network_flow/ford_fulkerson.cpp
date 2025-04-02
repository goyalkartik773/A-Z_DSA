#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<vector<int>> &graph, int source, int sink, vector<int> &parent, vector<bool> &visited)
{
    // this dfs function will find an augmented path in a graph if exists --> return true else --> return false;
    visited[source] = true;
    if (source == sink)
        return true;
    for (int v = 0; v < graph.size(); v++)
    {
        if (!visited[v] && graph[source][v] > 0)
        {
            parent[v] = source;
            if (dfs(graph, v, sink, parent, visited))
                return true;
        }
    }
    return false;
}
int ford_fulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<vector<int>> &residual_graph = graph;
    vector<int> parent(graph.size(), -1);
    int max_flow = 0;
    while (true)
    {
        vector<bool> visited(graph.size(), false);
        // agar koi bhi augmented path nahi milta hai to return false kardega
        if (!dfs(residual_graph, source, sink, parent, visited))
            break;
        // agar path exist karta hai to uska bottle neck capacity(min_capacity) ko find karega
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        // updating the residual capacity of the augmented path
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residual_graph[u][v] -= path_flow; // forward side shows the remaining capacity after the flow of path_flow
            residual_graph[v][u] += path_flow; // backward side shows the path_flow
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    // this algorithm finds the maximum flow from source to sink
    vector<vector<int>> graph =
        {{0, 11, 12, 0, 0, 0},
         {0, 0, 0, 12, 0, 0},
         {0, 1, 0, 0, 11, 0},
         {0, 0, 0, 0, 0, 19},
         {0, 0, 0, 7, 0, 4},
         {0, 0, 0, 0, 0, 0}}; // sink no edges is outgoing
    int source = 3;
    int sink = 5;
    cout << ford_fulkerson(graph, source, sink);
}