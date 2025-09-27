#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Longest Increasing Subsequence
// O(n^2) time and O(n) space
int f(vector<int> &arr, int idx, int prev) {
  if (idx >= arr.size())
    return 0;
  int leftans = 0;
  int rightans = 0;
  if (prev == -1 || prev < arr[idx]) {
    leftans = 1 + f(arr, idx + 1, arr[idx]);
  }
  rightans = f(arr, idx + 1, prev);
  return max(leftans, rightans);
}
int ftd(vector<int> &arr, vector<vector<int>> &dp, int idx, int prev) {
  if (idx >= arr.size())
    return 0;
  if (dp[idx][prev + 1] != -1)
    return dp[idx][prev + 1];
  int leftans = 0;
  int rightans = 0;
  if (prev == -1 || prev < arr[idx]) {
    leftans = 1 + f(arr, idx + 1, arr[idx]);
  }
  rightans = f(arr, idx + 1, prev);
  return dp[idx][prev + 1] = max(leftans, rightans);
}
int fbu(vector<int> &arr) {
  int n = arr.size();
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}
int main() {
  vector<int> arr = {48, 37, 41, 38, 2};
  vector<vector<int>> dp(1000, vector<int>(1000, -1));
  cout << ftd(arr, dp, 0, -1);
  // patientce sorting approach
  /*
   vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<int> lis;
    lis.push_back(nums[0]);
    int n = nums.size();
    for(int i=1;i<n;i++){
        int ele = nums[i];
        bool flag = false;
        for(int j=0;j<lis.size();j++){
            if(ele < lis[j]){
                lis[j] = ele;
                flag = true;
                break;
            }
        }
        if(!flag){
            lis.push_back(ele);
        }
    } */
}