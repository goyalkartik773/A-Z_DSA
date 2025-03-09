#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> pr;
void prims_algo(vector<pair<int, int>> graph[], vector<bool> &visited, int src, int cost, vector<int> &parent)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, {src, -1}}); // {wt,{node,parent}}; prims mai starting node chaiye hota hai
    while (pq.size() != 0)
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int prt = pq.top().second.second;
        pq.pop();
        cost += wt;
        parent[node] = prt;
        visited[node] = 1;
        for (auto neighbours : graph[node])
        {
            if (!visited[neighbours.second])
            {
                pq.push({neighbours.first, {neighbours.second, node}});
            }
        }
    }
}
int main()
{
}