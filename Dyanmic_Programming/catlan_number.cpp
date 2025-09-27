#include <iostream>
#include <vector>
using namespace std;
int f(int n) {
  if (n <= 1)
    return 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f(i - 1) * f(n - i);
  }
  return ans;
}
int ftd(int n, vector<int> &dp) {
  if (n <= 1)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f(i - 1) * f(n - i);
  }
  return dp[n] = ans;
}
int fbu(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int len = 2; len <= n; len++) {
    int ans = 0;
    for (int i = 1; i <= len; i++) {
      ans += dp[i - 1] * dp[len - i];
    }
    dp[len] = ans;
  }
  return dp[n];
}
int main() {
  int n = 19;
  for(int i=1;i<=19;i++)
  cout << fbu(i)<<endl;
  return 0;
};
