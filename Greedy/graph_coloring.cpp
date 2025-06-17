#include<iostream>
#include<vector>
using namespace std;
void graph_coloring(vector<vector<int>>& graph,vector<int>& result)
{
    // greedy approach assign minimum possible color to each node
    int V = graph.size();
    // maximum color to color the graph will be no of vertices;
    // vector<int> result(V,-1); // store the color of each node
    result[0] = 0;
    vector<bool> available(V,true); // intially all the colors are available
    for(int u=1; u<V; u++)
    {
        for(int v=0; v<V; v++)
        {
            if(graph[u][v]>0 && result[v]!=-1)
            {
                available[result[v]] = false;
                // adjacent node ke color ko unavailable kardo ye color nahi karsakte adjancent node ka
            }
        }
        int cr;
        // greedy approach jo minimum color available mil jaye directly utha lo
        for( cr = 0; cr<V; cr++)
        {
            if(available[cr])
                break;
        }
        result[u] = cr;
        // adjacent node ke color ko abb available kardo
        for(int v = 0; v<V; v++)
        {
            if(graph[u][v]>0 && result[v]!=-1)
                available[result[v]] = true;
        }
    }
}
int main()
{
vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    int V = graph.size();
    vector<int> result(V,-1);
    graph_coloring(graph,result);
    for(int i=0;i<V;i++){
        cout<<i<<"->"<<result[i]<<endl;
    }

}
