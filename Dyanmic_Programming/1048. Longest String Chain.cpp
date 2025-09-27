#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool customComparator(string &a, string &b) { return a.size() < b.size(); }
vector<vector<int>> dp;
bool isPredecessor(vector<string> &words, int prev, int idx) {
  string word1 = words[prev];
  string word2 = words[idx];
  if (word1.size() + 1 != word2.size())
    return false;
  int flips = 0;
  int i = 0;
  int j = 0;
  while (i < word1.size() && j < word2.size()) {
    if (word1[i] == word2[j]) {
      i++;
      j++;
    } else {
      flips++;
      j++;
      if (flips > 1)
        return false;
    }
  }
  return true;
}
int ftd(vector<string> &words, int prev, int idx) {
  if (idx >= words.size())
    return 0;
  if (dp[prev + 1][idx] != -1)
    return dp[prev + 1][idx];
  int skip = 0 + ftd(words, prev, idx + 1);
  int take = 0;
  if (prev == -1) {
    take = 1 + ftd(words, idx, idx + 1);
  } else {
    if (isPredecessor(words, prev, idx)) {
      take = 1 + ftd(words, idx, idx + 1);
    }
  }
  return dp[prev + 1][idx] = max(skip, take);
}
int longestStrChain(vector<string> &words) {
  sort(words.begin(), words.end(), customComparator);
  int n = words.size();
  dp.assign(n + 1, vector<int>(n + 1, -1));
  return ftd(words, -1, 0);
}

int main() {
    
}