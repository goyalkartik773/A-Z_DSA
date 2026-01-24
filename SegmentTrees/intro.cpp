// User function Template for C++
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution {
public:
  void buildSegmentTree(vector<int> &segmentTree, int arr[], int idx, int left,int right) {
    if (left == right) {
      segmentTree[idx] = arr[left];
      return;
    }
    int mid = left + (right - left) / 2;
    buildSegmentTree(segmentTree, arr, 2 * idx + 1, left, mid);
    buildSegmentTree(segmentTree, arr, 2 * idx + 2, mid + 1, right);
    segmentTree[idx] = segmentTree[2 * idx + 1] + segmentTree[2 * idx + 2];
  }

  void updateSegmentTree(vector<int> &segmentTree, int i, int idx, int val,int left, int right) {
    if (left == right) {
      segmentTree[i] = val;
      return;
    }
    int mid = left + (right - left) / 2;

    if (idx <= mid) {
      updateSegmentTree(segmentTree, 2 * i + 1, idx, val, left, mid);
    } else {
      updateSegmentTree(segmentTree, 2 * i + 2, idx, val, mid + 1, right);
    }

    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
  }

  int rangeSumQuery(vector<int> &segmentTree, int i, int start, int end,int left, int right) {

    // No overlap
    if (right < start || left > end)
      return 0;

    // Total overlap
    if (left >= start && right <= end)
      return segmentTree[i];

    int mid = left + (right - left) / 2;

    return rangeSumQuery(segmentTree, 2 * i + 1, start, end, left, mid) +
           rangeSumQuery(segmentTree, 2 * i + 2, start, end, mid + 1, right);
  }

  vector<int> querySum(int n, int arr[], int q, int queries[]) {
    vector<int> segmentTree(4 * n);
    buildSegmentTree(segmentTree, arr, 0, 0, n - 1);

    vector<int> result;

    // Each query has 2 values: L and R
    for (int i = 0; i < 2 * q; i += 2) {
      int L = queries[i] - 1;
      int R = queries[i + 1] - 1;

      result.push_back(rangeSumQuery(segmentTree, 0, L, R, 0, n - 1));
    }

    return result;
  }
};
int main() {}