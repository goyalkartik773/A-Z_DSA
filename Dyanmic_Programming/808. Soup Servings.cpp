#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> arr = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
vector<vector<double>> dp;

double ftd(int a, int b) {
  if (a <= 0 && b <= 0)
    return 0.5; // both empty
  if (a <= 0)
    return 1.0; // only A empty
  if (b <= 0)
    return 0.0; // only B empty
  if (dp[a][b] != -1.0)
    return dp[a][b];

  double result = 0.0;
  for (int i = 0; i < 4; i++) {
    // int newa = ;
    // int newb = ;
    result += ftd(max(a - arr[i][0], 0), max(b - arr[i][1], 0));
  }
  return dp[a][b] = 0.25 * result;
}
double soupServings(int n) {
  if (n > 5000)
    return 1.0;
  dp.resize(n + 1, vector<double>(n + 1, -1.0));
  return ftd(n, n);
}

int main() {}