#include <iostream>
#include <vector>
using namespace std;
bool can_move(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i < 0 || i >= n || j < 0 || j >= m) // boundary check
        return false;
    if (grid[i][j] == 1) // obstacle check
        return false;

    return true;
}
int f(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i == n - 1 && j == m - 1)
        return 1;
    int downways = 0;
    int rightways = 0;
    if (can_move(i, j + 1, n, m, grid))
        rightways += f(i, j + 1, n, m, grid); // move right
    if (can_move(i + 1, j, n, m, grid))
        downways += f(i + 1, j, n, m, grid); // move down

    return rightways + downways;
}
int ftd(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    return 1;
    if (dp[i][j] != -1)
    return dp[i][j];
    int downways = 0;
    int rightways = 0;
    if (can_move(i, j + 1, n, m, grid))
    // move right;
    rightways += ftd(i, j + 1, n, m, grid, dp);
    if (can_move(i + 1, j, n, m, grid))
    // move down
     downways += ftd(i + 1, j, n, m, grid, dp);
    
    return dp[i][j] = rightways + downways;
}
int fbu(vector<vector<int>> &grid, vector<vector<int>> &dp){
    // bottom up approach
    int n = grid.size();
    int m = grid[0].size();
    dp.resize(n, vector<int>(m, 0));
    dp[n-1][m-1] = 1; // base case, only one way to reach the destination from itself
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1)
            continue; // skip the destination cell
            if(can_move(i,j+1,n,m,grid))
            dp[i][j] += dp[i][j+1]; // move right
            if(can_move(i+1,j,n,m,grid))
            dp[i][j] += dp[i+1][j]; // move down
        }
    }
    return dp[0][0]; // return the number of ways to reach the destination from the source
}
int main()
{
    int n, m;
    cin >> n >> m; // input the dimensions of the grid
    vector<vector<int>> grid(n, vector<int>(m, 0)); // initialize the grid with 0s
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j]; // input the grid values

    vector<vector<int>> dp(n, vector<int>(m, -1)); // initialize the dp array with -1
    cout << ftd(0, 0, n, m, grid, dp) << endl; // top down approach
    cout << fbu(grid, dp) << endl; // bottom up approach
}
