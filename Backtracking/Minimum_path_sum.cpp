#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int ans = INT_MAX;
bool can_move(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i < 0 || i >= n || j < 0 || j >= m) // only boundary check
        return false;
    return true;
}
void f1(int i, int j, int n, int m, vector<vector<int>> &grid, int sum)
{
    if (i == n - 1 && j == m - 1)
    {
        sum += grid[i][j]; // return the destination;
        ans = min(ans, sum);
        return;
    }
    sum += grid[i][j];
    if (can_move(i, j + 1, n, m, grid))
        f1(i, j + 1, n, m, grid, sum);
    if (can_move(i + 1, j, n, m, grid))
        f1(i + 1, j, n, m, grid, sum);
    sum -= grid[i][j];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    f1(0, 0, n, m, grid, 0);
    cout << ans << endl; // print the minimum path sum
    // ans will be the minimum path sum from (0,0) to (n-1,m-1)

    return 0;
}