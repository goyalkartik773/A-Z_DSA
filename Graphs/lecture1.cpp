#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
// representation of the graph Adjancy list unweighted
vector<list<int>> graph;
void add_edge(int src, int dest, bool dir = true) {
  graph[src].push_back(dest);
  if (dir)
    graph[dest].push_back(src);
}
void remove_edge(int src, int dest, bool dir = true) {
  graph[src].remove(dest);
  if (dir)
  graph[dest].remove(src);
}
void display_graph() {
  for (int i = 0; i < graph.size(); i++) {
    cout << i << "->";
    for (auto ele : graph[i]) {
      cout << ele << ",";
    }
    cout << endl;
  }
}
// void add_edge(int src, int dest, int wt, bool dir = true) {
//   graph[src].push_back({dest, wt});
//   if (dir)
//   graph[dest].push_back({dest, wt});
// }
// void remove_edge(int src, int dest, int wt, bool dir = true) {
//   graph[src].remove({dest, wt});
//   if (dir)
//     graph[dest].remove({src, wt});
// }
// void display_graph() {
//   for (int i = 0; i < graph.size(); i++) {
//     cout << i << "->";
//     for (auto ele : graph[i]) {
//     cout << ele.first << "," << ele.second << ",";
//     }
//     cout << endl;
//   }
// }

// graph traversals Ist --> DFS O(v+E)
//Q1 --> find wether there exist a path between two node or not
bool dfs(int src,int dest,vector<bool>& visited){
    if(src==dest)
    return true; // path milgaya return karjao
    visited[src] = true;
    for(auto neighbours:graph[src]){
        if(!visited[neighbours]){
        if(dfs(neighbours,dest,visited))
        return true; // agar koi ek path bhi exist kargaya to wahi true return kardiya

        }
    }
    return false;
}
//Q2 --> find all paths exists between two nodes
vector<string> ans;
void dfsAllPath(int src,int des,string& str,vector<bool>& visited){
    if(src==des)
    {
        // ek path milgaya hai
        str+=to_string(des);
        ans.push_back(str);
        return;
    }
    visited[src] = true;
    str += to_string(src);
    for(auto neighbours:graph[src]){
        if(!visited[neighbours]){
            dfsAllPath(neighbours,des,str,visited);
        }
    }
    visited[src] = false;
    str.pop_back();
}

// BFS Traversal (Shortest distance from source node to all)  --> O(V+E)
vector<int> shortestDistance(7,0);
void BFS(int src,vector<bool>& visited){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    shortestDistance[src] = 0;
    while(q.size()!=0){
        int node = q.front();
        q.pop();
        // koi node ko queue mai push karega tab hi usse visited bhi mark karlega
        for(auto neighbours:graph[node]){
            if(!visited[neighbours]){
                visited[neighbours] = true;
                q.push(neighbours);
                shortestDistance[neighbours] = 1 + shortestDistance[node];
            }
        }
    }
}
int main() {
  int v;
  cin >> v;
  graph.resize(v,list<int>());
  int e;
  cin >> e;
  while (e--) {
    int src, dest;
    cin >> src >> dest;
    add_edge(src, dest);
  }
//   display_graph();
//   cout<<endl;
    vector<bool> visited(v,false);
    // string str = "";
    // dfsAllPath(0,7,str,visited);
    // for(auto ele:ans){
    //     cout<<ele<<" ";
    // }
    // if(dfs(0,7,visited)){
    //     cout<<"Path exist btween two node";
    // }
    BFS(0,visited);
    for(auto ele:shortestDistance){
        cout<<ele<<" ";
    }
}