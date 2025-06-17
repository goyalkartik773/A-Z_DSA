#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;
bool is_safe(vector<vector<int>> &graph, vector<int> &path, int idx, int node)
{
    // jo bhi node ko hamilton ka part banana chat hooo wo node path mai include nahi hona chaiye
    for (int i = 0; i <= idx; i++)
    {
        if (path[i] == node)
            return false;
    }
    // jo node le rah ho wo pichle node sai connected bhi hona chaiye
    if (graph[path[idx - 1]][node] == 0)
    {
        return false;
    }
    return true;
}
bool hamiltonain_cycle(vector<vector<int>> &graph, vector<int> &path, int idx)
{
    if (idx == graph.size())
    {
        // solution milgaya hao
        ans.push_back(path);
        return true;
    }
    // try to place all vertice in path
    for (int i = 1; i < graph.size(); i++)
    {
        if (is_safe(graph, path, idx, i))
        {
            path[idx] = i;
            if (hamiltonain_cycle(graph, path, idx + 1))
                return true;
            path[idx] = -1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> graph =
        {
            {0, 1, 1, 0, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 0, 1, 0},
            {0, 1, 1, 0, 1},
            {1, 1, 0, 1, 0}};
    vector<int> path(graph.size(), -1);
    path[0] = 0; // starting from zero node // gives only path which starts from zero
    bool flag = hamiltonain_cycle(graph, path, 1);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {

            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
