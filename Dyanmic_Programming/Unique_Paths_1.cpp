#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// this problem is to find the number of unique paths from top left to bottom right of a grid
bool can_move(int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n) // boundary check
        return false;
    return true;
}
int f(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i < 0 || i >= m || j < 0 || j >= n) // boundary check
        return 0;
    int right_ways = f(i, j + 1, m, n);
    int down_Ways = f(i + 1, j, m, n);
    return right_ways + down_Ways;
}
int ftd(int i, int j, int m, int n, vector<vector<long long>> &dp)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i < 0 || i >= m || j < 0 || j >= n) // boundary check
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right_ways = ftd(i, j + 1, m, n, dp);
    int down_Ways = ftd(i + 1, j, m, n, dp);
    return dp[i][j] = right_ways + down_Ways;
}
int fbu(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                continue;
            int right_ways = 0;
            if (can_move(i, j + 1, m, n))
                right_ways = dp[i][j + 1];
            int down_ways = 0;
            if (can_move(i + 1, j, m, n))
                down_ways = dp[i + 1][j];
            dp[i][j] = right_ways + down_ways;
        }
    }
    return dp[0][0];
}
int main()
{

    int m = 3, n = 7; // dimensions of the grid
    // vector<vector<long long>> dp(m, vector<long long>(n, -1));   
    // cout << ftd(0, 0, m, n, dp); // top down approach
    cout << fbu(m, n); // bottom up approach
    // cout << f(0, 0, m, n); // recursive approach
    // Output: 28, which is the number of unique paths from top left to bottom right
    // of a 3x7 grid.
    return 0;
}