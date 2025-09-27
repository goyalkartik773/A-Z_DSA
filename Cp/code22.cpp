#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int idx = 0; idx < n; ++idx) {
            if (dp[idx] >= INT_MAX) {
                continue;
            }
            if (idx + 1 <= n) {
                long long r1 = dp[idx] + (long long)costs[idx] + 1*1;
                dp[idx + 1] = min(dp[idx + 1], r1);
            }

            if (idx + 2 <= n) {
                long long r2 = dp[idx] + (long long)costs[idx + 1] + 2*2;
                dp[idx + 2] = min(dp[idx + 2], r2);
            }

            if (idx + 3 <= n) {
                long long r3 = dp[idx] + (long long)costs[idx + 2] + 3*3;
                dp[idx + 3] = min(dp[idx + 3], r3);
            }
        }
        return dp[n];
    }
};
int main(){
    
}