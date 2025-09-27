#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
  void dfs(int row, int col, vector<vector<int>> &grid,
           queue<pair<int, int>> &q, vector<vector<bool>> &visited) {
    if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0)
      return;

    visited[row][col] = true;
    grid[row][col] = 2;

    for (int d = 0; d < 4; d++) {
      int newRow = row + dir[d][0];
      int newCol = col + dir[d][1];

      if (newRow >= grid.size() || newRow < 0 || newCol >= grid[0].size() ||
          newCol < 0)
        continue;

      if (visited[newRow][newCol])
        continue;

      if (grid[newRow][newCol] == 0) {
        // reached land matlab row,col border wala cell hai push in
        // queue
        q.push({row, col});
        continue;
      }
      dfs(newRow, newCol, grid, q, visited);
    }
  }
  int shortestBridge(vector<vector<int>> &grid) {
    // exactly two island(1 component) present hai grid mai
    // step1 to identify both component differently mark all cells of one
    // component differently lets say2
    queue<pair<int, int>> q;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    bool flag = false;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          dfs(i, j, grid, q, visited);
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }

    // abb jo ye queue hai this contain boundary components iss sai
    // multisource bfs lagadunga
    int distance = 0;
    while (q.size() != 0) {
      queue<pair<int, int>> temp;
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // this current cell can go to four direction lets visit
        for (int d = 0; d < 4; d++) {
          int newRow = row + dir[d][0];
          int newCol = col + dir[d][1];

          if (newRow >= grid.size() || newRow < 0 || newCol >= grid[0].size() ||
              newCol < 0)
            continue;

          if (grid[newRow][newCol] == 2)
            continue;

          if (grid[newRow][newCol] == 1)
            return distance; // doosra component milgaya
          // matlab bich mai pani hai
          temp.push({newRow, newCol});
          grid[newRow][newCol] = 2;
        }
      }
      // har level bfs ke baad distance ko increase kardo
      distance++;
      q = temp;
    }
    return distance;
  }
};
int main() {
    
}