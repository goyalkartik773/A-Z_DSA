#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp2, dp3;

int ftdChild2(int i, int j, vector<vector<int>> &fruits) {
  if (i >= fruits.size() || i < 0 || j >= fruits[0].size() || j < 0)
    return 0;
  if (i == j || j < i)
    return 0;
  if (dp2[i][j] != -1)
    return dp2[i][j];

  int choice1 = fruits[i][j] + ftdChild2(i + 1, j - 1, fruits);
  int choice2 = fruits[i][j] + ftdChild2(i + 1, j, fruits);
  int choice3 = fruits[i][j] + ftdChild2(i + 1, j + 1, fruits);
  return dp2[i][j] = max({choice1, choice2, choice3});
}

int ftdChild3(int i, int j, vector<vector<int>> &fruits) {
  if (i >= fruits.size() || i < 0 || j >= fruits[0].size() || j < 0)
    return 0;
  if (i == j || j > i)
    return 0;
  if (dp3[i][j] != -1)
    return dp3[i][j];

  int choice1 = fruits[i][j] + ftdChild3(i - 1, j + 1, fruits);
  int choice2 = fruits[i][j] + ftdChild3(i, j + 1, fruits);
  int choice3 = fruits[i][j] + ftdChild3(i + 1, j + 1, fruits);
  return dp3[i][j] = max({choice1, choice2, choice3});
}

int maxCollectedFruits(vector<vector<int>> &fruits) {
  int totalFruits = 0;
  int n = fruits.size();

  // child1
  for (int i = 0; i < n; i++) {
    totalFruits += fruits[i][i];
    fruits[i][i] = 0;
  }

  dp2.assign(n, vector<int>(n, -1));
  dp3.assign(n, vector<int>(n, -1));
  totalFruits += ftdChild2(0, n - 1, fruits);
  totalFruits += ftdChild3(n - 1, 0, fruits);
  return totalFruits;
}

int main() {
    
}