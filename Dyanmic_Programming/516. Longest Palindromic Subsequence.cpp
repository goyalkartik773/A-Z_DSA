#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t[1001][1001];
int f(string &s, int i, int j) {
  if (i > j)
    return 0;

  if (i == j)
    return 1;

  if (s[i] == s[j]) {
    return 2 + f(s, i + 1, j - 1);
  } else {
    return max(f(s, i + 1, j), f(s, i, j - 1));
  }
}
int ftd(string &s, int i, int j) {
  if (i > j)
    return 0;
  if (t[i][j] != -1)
    return t[i][j];
  if (i == j)
    return 1;
  if (s[i] == s[j]) {
    return t[i][j] = 2 + f(s, i + 1, j - 1);
  } else {
    return t[i][j] = max(f(s, i + 1, j), f(s, i, j - 1));
  }
}
int fbu(string &s) {
  int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; len + i - 1 < n; i++) {
      int j = len + i - 1;
      if (s[i] == s[j])
        dp[i][j] = 2 + dp[i + 1][j - 1];
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[0][n - 1];
}
int main() {

}