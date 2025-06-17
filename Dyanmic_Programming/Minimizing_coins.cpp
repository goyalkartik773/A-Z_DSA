#include <iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int> dp(100,-1);
int f(int x,vector<int>& coins){
if(x==0)
    return 0;
int ans = INT_MAX;
for(int i=0;i<coins.size();i++){
    if(x >= coins[i])
    ans = min(ans,1+f(x-coins[i],coins));
}
return ans;
}
int ftd(int x,vector<int>& coins){
if(x==0)
    return 0;
if(dp[x]!=-1)
    return dp[x];
int ans = INT_MAX;
for(int i=0;i<coins.size();i++){
    if(x >= coins[i])
    ans = min(ans,1+ftd(x-coins[i],coins));
}
return dp[x]=ans;
}
int fbu(int x,vector<int>& coins){
dp[0]=0;
for(int i=1;i<=x;i++){
    int ans = INT_MAX;
    for(int j=0;j<coins.size();j++){
        if(i>=coins[j]){
            ans = min(ans,1+dp[i-coins[j]]);
        }
    }
    dp[i] = ans;
}
return dp[x];
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n,0);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<ftd(x,coins);
}
