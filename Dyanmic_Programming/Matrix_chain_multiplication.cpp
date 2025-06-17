#include<iostream>
#include<vector>
using namespace std;
int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
if(i==j || i+1==j )
    return 0;
if(dp[i][j]!=-1)
    return dp[i][j];
int ans = INT_MAX;
for(int k=i+1;k<j;k++){
    ans = min(ans,f(i,k,arr,dp)+f(k,j,arr,dp) + arr[i]*arr[k]*arr[j]);
}
return dp[i][j]=ans;
}
int fbu(vector<int>& arr,vector<vector<int>>& dp){
    int n = arr.size();
    dp.resize(n+1,vector<int>(n+1,0));
    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j = i+len-1;
            int ans = INT_MAX;
            for(int k=i+1;k<j;k++){
                ans = min(ans,dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1];
}
int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = arr.size();
    vector<vector<int>> dp;//(n+1,vector<int>(n+1,-1));
   // cout<<f(0,n-1,arr,dp);
   cout<<fbu(arr,dp);

}
