#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSubstrings(string s) {
  // approach 1 bruteforce ki sare substring ko nikalkar check ki wo
  // palindorme hai THATS T.C --> O(N^3); approach2 optimising approach 1
  // ki when you are checking whether the substring is palindrome or not
  // do memoization --> O(N^2) approach3 using bottom up approach T.C
  // O(N^2 - N)/2 --> O(N^2)

  int n = s.length();
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  int count = 0;
  for (int len = 1; len <= n; len++) {
    for (int i = 0; len + i - 1 < n; i++) {
      int j = len + i - 1;
      if (i == j) {
        dp[i][j] = true;
        count++;
      } else if (i + 1 == j) {
        if (s[i] == s[j]) {
          dp[i][j] = true;
          count++;
        } else
          dp[i][j] = false;
      } else {
        if (dp[i + 1][j - 1]) {
          if (s[i] == s[j]) {
            dp[i][j] = true;
            count++;
          } else
            dp[i][j] = false;
        } else
          dp[i][j] = false;
      }
    }
  }
  return count;
}
int main() {
    
}