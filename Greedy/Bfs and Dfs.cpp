#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void bfs(vector<vector<int>> &graph, vector<bool> &visited, int src, vector<int> &dis)
{
    // if graph is unweighted we can find the shortest distance from source node to every node using bfs
    visited[src] = 1;
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while (q.size() != 0)
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto neighbours : graph[node])
        {
            if (!visited[neighbours])
            {
                // neighbour node ko abhi visit nahi kiya hai
                q.push(neighbours);
                dis[neighbours] = dis[node] + 1;
                visited[neighbours] = 1;
            }
        }
    }
}
void dfs_rec(vector<vector<int>> &graph, int src, vector<bool> &visited)
{
    visited[src] = 1;
    cout << src << " ";
    for (auto neighbours : graph[src])
    {
        if (!visited[neighbours])
        {
            dfs_rec(graph, neighbours, visited);
        }
    }
}
void dfs_stk(vector<vector<int>> &graph, int src, vector<bool> &visited)
{
    visited[src] = 1;
    stack<int> st;
    st.push(src);
    while (st.size() != 0)
    {
        int node = st.top();
        st.pop();
        cout << node << " ";
        for (auto neighbours : graph[node])
        {
            if (!visited[neighbours])
            {
                st.push(neighbours);
                visited[neighbours] = 1;
            }
        }
    }
}
void display(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (auto ele : graph[i])
        {
            cout << ele << ",";
        }
        cout << endl;
    }
}
int main()
{
    int vertices, edges;
    cout << "Enter no of vertices and edges\n";
    cin >> vertices >> edges;
    vector<vector<int>> adj(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "enter edges like (u,v)\n";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(vertices, 0);
    vector<int>  distance(vertices, 0);
    // bfs(adj,visited,0,distance);
    // cout<<"\ncloseset distance from source node\n";
    // for(auto ele :distance){
    //     cout<<ele<<" ";
    // }
    dfs_stk(adj, 0, visited);
    // display(adj);
}