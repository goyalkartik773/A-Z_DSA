#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int dp[301][301];
long long ipow(int base, int exp) {
  long long result = 1;
  while (exp--)
    result *= base;
  return result;
}
int ftd(int n, int idx, int x) {
  if (n == 0)
    return 1;
  if (idx > n)
    return 0;
  if (dp[n][idx] != -1)
    return dp[n][idx];

  long long num = ipow(idx, x);
  if (num > n)
    return 0;
  int skip = ftd(n, idx + 1, x);
  int take = 0;
  if (num <= n) {
    take = ftd(n - num, idx + 1, x);
  }
  return dp[n][idx] = (skip + take) % MOD;
}
int numberOfWays(int n, int x) {
  memset(dp, -1, sizeof(dp));
  return ftd(n, 1, x);
}
int main() {}