#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> mpr;
void add_edge(vector<vector<int>> adj[], int u, int v, int wt)
{
    // graph is undirected
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
void display_graph(vector<vector<int>> adj[])
{
    cout << "graph adjancey list (u,v,wt) " << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << i << "-> ";
        for (auto ele : adj[i])
        {
            cout << ele[0] << "," << ele[1] << " ,";
        }
        cout << endl;
    }
    cout << endl;
}
bool check_path(vector<vector<int>> adj[], int src, int des, vector<bool> &is_visit)
{
    if (src == des)
        return true;

    is_visit[src] = true;
    for (auto neighbours : adj[src])
    {
        if (!is_visit[neighbours[0]])
        {
            if (check_path(adj, neighbours[0], des, is_visit))
            {
                return true;
            }
        }
    }

    return false;
}
int mst_cost(vector<vector<int>> adj[], int vertices)
{
    // step-1 push all the edges of the your graph in min heap by greedy approach always take optimal choice
    priority_queue<mpr, vector<mpr>, greater<mpr>> pq; // min heap --> {u,{v,wt}};
    for (int i = 0; i < vertices; i++)
    {
        for (auto ele : adj[i])
        {
            if (i < ele[0])                     // Ensures each edge is added only once
                pq.push({ele[1], {i, ele[0]}}); // {weight, {u, v}}
        }
    }

    int cost = 0;
    vector<vector<int>> mst[9]; // khud ka jo mst hum banate jayega uss per humme dfs lagana hai
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // Check if adding this edge creates a cycle
        vector<bool> is_visit(vertices, false);
        bool flag = check_path(mst, u, v, is_visit);

        // If no path exists between u and v, add it to MST
        if (!flag)
        {
            mst[u].push_back({v, wt});
            mst[v].push_back({u, wt});
            cost += wt;
        }
    }

    return cost;
}
int main()
{
    vector<vector<int>> adj[9];
    int edges = 12;
    // static input[programmer]
    // add_edge(adj, 0, 1, 4);
    // add_edge(adj, 0, 7, 8);
    // add_edge(adj, 1, 2, 8);
    // add_edge(adj, 7, 8, 7);
    // add_edge(adj, 7, 6, 1);
    // add_edge(adj, 6, 8, 6);
    // add_edge(adj, 2, 8, 2);
    // add_edge(adj, 2, 3, 7);
    // add_edge(adj, 6, 5, 2);
    // add_edge(adj, 3, 5, 14);
    // add_edge(adj, 3, 4, 9);
    // add_edge(adj, 5, 4, 10);
    adj[0] = {{1, 7}, {4, 4}, {7, 8}, {9, 3}};
    adj[1] = {{0, 7}, {7, 7}, {8, 3}};
    adj[2] = {{5, 8}, {7, 10}};
    adj[3] = {{4, 3}};
    adj[4] = {{0, 4}, {3, 3}, {6, 10}};
    adj[5] = {{2, 8}, {7, 8}};
    adj[6] = {{4, 10}};
    adj[7] = {{0, 8}, {1, 7}, {2, 10}, {5, 8}};
    adj[8] = {{1, 3}};
    adj[9] = {{0, 3}};
    // dynamic input[user]
    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v, wt;
    //     cout << "enter u v and wt" << endl;
    //     cin >> u >> v >> wt;
    //     add_edge(adj, u, v, wt);
    // }

    display_graph(adj);
    cout << mst_cost(adj, 9);
}