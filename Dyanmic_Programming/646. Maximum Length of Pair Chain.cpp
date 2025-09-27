#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool customComparator(vector<int> &p1, vector<int> &p2) {
  return p1[1] < p2[1];
}
vector<vector<int>> dp;

int ftd(vector<vector<int>> &pairs, int prev, int idx) {
  if (idx >= pairs.size())
    return 0;
  if (dp[prev + 1][idx] != -1)
    return dp[prev + 1][idx];
  int skip = 0 + ftd(pairs, prev, idx + 1);
  int take = 0;
  if (prev == -1) {
    take = 1 + ftd(pairs, idx, idx + 1);
  } else {
    if (pairs[idx][0] > pairs[prev][1])
      take = 1 + ftd(pairs, idx, idx + 1);
  }
  return dp[prev + 1][idx] = max(skip, take);
}
int findLongestChain(vector<vector<int>> &pairs) {
  // step1 sort the pairs taki ye array continous subsequence ki tarah treat kar
  // sake
  int n = pairs.size();
  sort(pairs.begin(), pairs.end(), customComparator);
  dp.assign(n + 1, vector<int>(n, -1));
  return ftd(pairs, -1, 0);
}
int main() {
    
}