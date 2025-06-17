#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool can_move(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}
int f(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i == n - 1 && j == m - 1)
        return grid[i][j];                  // return the destination;
    if (i < 0 || i >= n || j < 0 || j >= m) // only boundary check
        return INT_MAX;
    return grid[i][j] + min(f(i, j + 1, n, m, grid), f(i + 1, j, n, m, grid));
}
int ftd(int i, int j, int n, int m, vector<vector<int>> &grid,
        vector<vector<long long>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return grid[i][j];                  // return the destination;
    if (i < 0 || i >= n || j < 0 || j >= m) // only boundary check
        return INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] +
                      min(ftd(i, j + 1, n, m, grid, dp), ftd(i + 1, j, n, m, grid, dp));
}
int fbu(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n - 1][m - 1] = arr[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
                continue;
            else
            {
                int right = INT_MAX;
                if (can_move(i, j + 1, arr))
                    right = dp[i][j + 1];
                int down = INT_MAX;
                if (can_move(i + 1, j, arr))
                    down = dp[i + 1][j];
                dp[i][j] = arr[i][j] + min(right, down);
            }
        }
    }
    return dp[0][0];
}
int main()
{

    return 0;
}