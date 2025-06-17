#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    if(n==1){
        cout<< max(a,max(b,c));
    }
    else{
            vector<vector<int>> dp(n,vector<int>(3,-1));
        vector<vector<int>> arr(n,vector<int>(3,-1));
        dp[0][0] = a;
        dp[0][1] = b;
        dp[0][2] = c;
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<n;i++){
                dp[i][0] = arr[i][0] + max(dp[i-1][1],dp[i-1][2]);
                dp[i][1] = arr[i][1] + max(dp[i-1][0],dp[i-1][2]);
                dp[i][2] = arr[i][2] + max(dp[i-1][0],dp[i-1][1]);
        }
       cout<< max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
     }

}
