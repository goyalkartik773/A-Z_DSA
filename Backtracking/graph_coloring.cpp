#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
bool is_safe(vector<vector<int>>& graph,vector<int>& color,int c,int node)
{
    // ko bhi do adjacent node ka samecolor nahi hona chaiye
    for(auto neighbours:graph[node])
    {
        if(color[neighbours] == c)
            return false;
    }
    return true;
}
bool graph_coloring(vector<vector<int>>& graph,vector<int>& color,int node,int m)
{
    if(node == graph.size())
    {
// ek solution milgaya m color sai graph ko color karne kaa
        ans.push_back(color);
        return true;
    }
    for(int i=1; i<=m; i++)
    {
        // jitne possible color hai sabse color karna ka try karnga graph ke har ek node ko
        if(is_safe(graph,color,i,node))
        {
            color[node] = i;
            //if(graph_coloring(graph,color,node+1,m))
            //    return true;
            graph_coloring(graph,color,node+1,m);
            color[node] = 0; // backtrack karte samay color ko uncolor kardega
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    vector<int> color(4,0);
    int m = 3;
    bool flag = graph_coloring(graph,color,0,m);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
