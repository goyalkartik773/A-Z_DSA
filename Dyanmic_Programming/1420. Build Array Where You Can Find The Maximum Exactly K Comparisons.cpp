#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
using namespace std;

int dp[102][51][51];
const int MOD = 1e9 + 7;
long long ftd(int idx, int m, int n, int prev, int sc, int k) {
  if (idx == n) {
    return sc == k;
  }
  if (dp[prev + 1][idx][sc] != -1)
    return dp[prev + 1][idx][sc];

  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    if (prev == -1) {
      ans += ftd(idx + 1, m, n, i, sc + 1, k) % MOD;
    } else if (prev >= i) {
      ans += ftd(idx + 1, m, n, prev, sc, k) % MOD;
    } else {
      ans += ftd(idx + 1, m, n, i, sc + 1, k) % MOD;
    }
  }
  return dp[prev + 1][idx][sc] = ans % MOD;
}

int numOfArrays(int n, int m, int k) {
  memset(dp, -1, sizeof(dp));
  return ftd(0, m, n, -1, 0, k);
}

int main() {
    
}
