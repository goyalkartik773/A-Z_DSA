#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;
class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
        return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        vector<int> arr = nums;
        int n = arr.size();

        DSU dsu(n);
        for (auto ele : swaps) {
            dsu.unite(ele[0], ele[1]);
        }

        unordered_map<int, vector<long long>> mp1;
        unordered_map<int, vector<int>> mp2;

        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            mp1[root].push_back(arr[i]);
            mp2[root].push_back(i);
        }

        long long result = 0;

        for (auto const& [root, indices] : mp2) {
            vector<long long> brr = mp1.at(root);
            
            int evenCount = 0;
            for (int idx : indices) {
                if (idx % 2 == 0) {
                    evenCount++;
                }
            }
            
            sort(brr.rbegin(), brr.rend());

            for (int i = 0; i < evenCount; i++) {
                result += brr[i];
            }
            
            for (int i = evenCount; i < brr.size(); i++) {
                result -= brr[i];
            }
        }

        return result;
    }
};
int main(){

}