#include <iostream>
#include<vector>
#define mod 1000000007
using namespace std;
// state of dp = 2;
vector<vector<int>> dp(1000, vector<int>(1000, -1));
int f(int n, int k, int target) {
        if (n == 0 && target == 0)
        return 1;
        if (n == 0 && target != 0) // no of dices exhaust but target not zero no // // ways to make target
        return 0;
        int count = 0;
        for (int i = 1; i <= k; i++) {
        if (i > target)
        break;
    count =(count % mod + f(n - 1, k, target - i) % mod) %mod;
}
return count % mod;
}
int ftd(int n, int k, int target) {
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0) // no of dices exhaust but target not zero no // // ways to make target
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int count = 0;
        for (int i = 1; i <= k; i++) {
            if (i > target)
                break;
    count =(count % mod + f(n - 1, k, target - i) % mod) %mod;
}
return dp[n][target] = count % mod;
}
int fbu(int n,int x,int target){
    vector<vector<int>> dp(1000, vector<int>(1000, -1));
    dp.clear();
    dp[0][0] = 1; // if dices are exhaust and target is zero so one way exists
    for(int j=1;j<=target;j++){
        dp[0][j] = 0; // if dices are exhaust and target is not zero then no way exists
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 0; // if target is zero then no ways exists
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int count = 0;
            for(int k=1;k<=x;k++){
                if(k>j)
                break;
            count = (count % mod + dp[i-1][j-k] % mod) % mod;
            }
            dp[i][j] = count % mod;
        }
    }
    return dp[n][target];
}
int main()
{
    // int n;
    // cin>>n;
    // int k;
    // cin>>k;
    // int target;
    // cin>>target;
    cout<<fbu(2,6,7);
    return 0;
}
