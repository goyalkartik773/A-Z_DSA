#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
bool bfs(vector<vector<int>> &graph1, int source, int sink, vector<int> &parent)
{
    vector<bool> visited(graph1.size(), false);
    queue<int> q;
    q.push(source);
    parent[source] = -1;
    visited[source] = true;
    while (q.size() != 0)
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < graph1.size(); v++)
        {
            if (!visited[v] && graph1[u][v] > 0)
            {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == sink)
                    return true;
            }
        }
    }
    return false;
}
int edmaonds_karp(vector<vector<int>> &graph1, int source, int sink)
{
    vector<vector<int>> residual_graph1 = graph1;
    vector<int> parent(graph1.size(), -1);
    int max_flow = 0;
    while (true)
    {
        if (!bfs(residual_graph1, source, sink, parent))
            break;
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, residual_graph1[u][v]);
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residual_graph1[u][v] -= path_flow;
            residual_graph1[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int s = 0, s1 = 1, s2 = 2, a = 3, b = 4, c = 5, t1 = 6, t2 = 7, t = 8;
    vector<vector<int>> graph1 = {
        {0, INT_MAX, INT_MAX, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 50, 30, 0, 0, 0, 0},
        {0, 0, 0, 0, 40, 20, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 60, 0, 0},
        {0, 0, 0, 0, 0, 0, 30, 20, 0},
        {0, 0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, INT_MAX},
        {0, 0, 0, 0, 0, 0, 0, 0, INT_MAX},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int source = s;
    int sink = t;
    cout << "The maximum flow without maintaing any priority_order : "<<edmaonds_karp(graph1, source, sink) << endl;
    // now supplies are sending from warehouse to areas using priority edges
    // Graph as adjacency matrix (VxV)
    vector<vector<int>> graph2(9, vector<int>(9, 0));

    // Edges classified by priority
    map<string, vector<tuple<int, int, int>>> edges;

    // High-priority edges (processed first)
    edges["H"] = {{s1, a, 50}, {s2, b, 40}, {a, t1, 60}, {b, t2, 20}};

    // Medium-priority edges (processed second)
    edges["M"] = {{s1, b, 30}, {b, t1, 30}, {c, t2, 10}};

    // Low-priority edges (processed last)
    edges["L"] = {{s2, c, 20}};

    // connect super-source to warehouses (s -> s1, s2)
    graph2[s][s1] = INT_MAX;
    graph2[s][s2] = INT_MAX;

    // connect affected areas to super-sink (t1, t2 -> t)
    graph2[t1][t] = INT_MAX;
    graph2[t2][t] = INT_MAX;

    int totalMaxFlow = 0;

    // Process high, medium, and low priority edges separately
    for (auto priority : {"H", "M", "L"})
    {
        for (auto edge : edges[priority])
        {
            int u, v, cap;
            tie(u, v, cap) = edge;
            graph2[u][v] = cap; // add capacity
        }

        // Find max flow for current priority level
        int flow = edmaonds_karp(graph2, s, t);
        totalMaxFlow += flow;
    }

    cout << "the Maximum Flow while ensuring high-priority routes first: " << totalMaxFlow << endl;

    return 0;
}