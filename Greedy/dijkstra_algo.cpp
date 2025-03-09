#include <iostream>
#include <vector>
using namespace std;
int vertices = 6;
void add_edge(vector<vector<int>> adj[], int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
void display_graph(vector<vector<int>> adj[])
{
    cout << "graph adjancey list (u,v,wt) " << endl;
    for (int i = 0; i < vertices; i++)
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
void dijkstra_algo(vector<vector<int>> adj[], vector<int> &distance, vector<int> &is_visit)
{
    // solved using greedy approach kyuki har baar vo node choose kar rahe hai jo minimum distance per hai local optimise choice lena ke baad backtrack karna ka koi chance nahi hai
    for (int i = 0; i < vertices; i++)
    {
        int idx = -1;
        int min = INT_MAX;
        for (int i = 0; i < vertices; i++)
        {
            if (!is_visit[i])
            {
                if (min > distance[i])
                {
                    min = distance[i];
                    idx = i;
                }
            }
        }
        is_visit[idx] = 1; // har ek iteration mai ek node visit ho jayega iss algo ko v time run karna taki sare nodes explored ho jaye
        for (auto neighbours : adj[idx])
        {
            if (!is_visit[neighbours[0]])
            {
                if (distance[idx] + neighbours[1] < distance[neighbours[0]])
                {
                    distance[neighbours[0]] = distance[idx] + neighbours[1];
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> adj[6];
    add_edge(adj, 0, 1, 6);
    add_edge(adj, 0, 2, 2);
    add_edge(adj, 1, 3, 7);
    add_edge(adj, 1, 2, 3);
    add_edge(adj, 2, 4, 4);
    add_edge(adj, 3, 4, 5);
    add_edge(adj, 3, 5, 2);
    add_edge(adj, 4, 5, 9);
    display_graph(adj);
    vector<int> dist(vertices, INT_MAX);
    vector<int> is_visit(vertices, 0);
    int src = 0;
    dist[src] = 0;
    dijkstra_algo(adj, dist, is_visit);
    for (auto ele : dist)
        cout << ele << " ";
}
