#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
// this algorithm is called BRIAN KERNIGHANS ALGO
    int count_set_bit(int num) {
        int count = 0;
        while (num != 0) {
            count++;
            num = (num & num - 1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            ans[i] = count_set_bit(i);
        }
        return ans;
    }
};