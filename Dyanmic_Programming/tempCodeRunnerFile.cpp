#include <iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;
// this problem is application of matrix chain multiplication
// here we have to find the minimum smoke generated after mixing all the mixtures
int ftd(int i,int j,vector<int>& arr,vector<vector<int>>& dp) {
	if(i==j)
		return 0; // only one mixture no smoke generated
	if(dp[i][j]!=-1)
	return dp[i][j];
	int ans = INT_MAX;
	for(int k=i; k<j; k++) {
		// k no of splits kar sakta huu mixtures mai

		int left_mixtures = 0; // this gives the color1 after mixing i to k mixtures
		for(int x = i; x<=k; x++) {
			left_mixtures+=arr[x];
		}
		left_mixtures = left_mixtures%100;
		int right_mixtures = 0; // this gives the color2 after mixing k+1 to j mixtures
		for(int x = k+1; x<=j; x++) {
			right_mixtures+=arr[x];
		}
		right_mixtures=right_mixtures%100;
		ans = min(ans,(ftd(i,k,arr,dp)+ftd(k+1,j,arr,dp)+left_mixtures*right_mixtures));
	}
	return dp[i][j]=ans;
}
int fbu(vector<int>& arr,vector<vector<int>>& dp){
    int n = arr.size();
    dp.resize(n,vector<int>(n,0)); // if problem size is less than 2 then no smoke generated
    for(int len = 2;len<=n;len++){
       for(int i=0;i<n-len+1;i++){
        int j = i+len-1;
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            // k no of splits kar sakta huu mixtures mai

            int left_mixtures = 0; // this gives the color1 after mixing i to k mixtures
            for(int x = i; x<=k; x++) {
                left_mixtures+=arr[x];
            }
            left_mixtures = left_mixtures%100;
            int right_mixtures = 0; // this gives the color2 after mixing k+1 to j mixtures
            for(int x = k+1; x<=j; x++) {
                right_mixtures+=arr[x];
            }
            right_mixtures=right_mixtures%100;
            ans = min(ans,(dp[i][k]+dp[k+1][j]+left_mixtures*right_mixtures));
        }
        dp[i][j] = ans;
       } 
    }
    return dp[0][n-1];

}
int main()
{
    vector<int> ans;
    int n;
    while(cin>>n){
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        cout<<fbu(arr,dp)<<endl;
        arr.clear();
    }
}
