#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
  int n = s.length();
  int maxLen = 1;
  int idx = 0;
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    dp[i][i] = true; // single length string always a palindrome
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; len + i - 1 < n; i++) {
      int j = len + i - 1;
      if (i + 1 == j) {
        if (s[i] == s[j]) {
          maxLen = max(maxLen, j - i + 1);
          idx = i;
          dp[i][j] = true;
        } else {
          dp[i][j] = false;
        }
      } else {
        if (dp[i + 1][j - 1]) {
          if (s[i] == s[j]) {
            maxLen = max(maxLen, j - i + 1);
            idx = i;
            dp[i][j] = true;
          } else {
            dp[i][j] = false;
          }
        }

        else {
          dp[i][j] = false;
        }
      }
    }
  }
  return s.substr(idx, maxLen);
}
int main() {
    
}