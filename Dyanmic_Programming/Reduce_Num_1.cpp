#include<iostream>
#include<vector>
using namespace std;
vector<int> dp(1000,-1);
int f(int num)
{
    if(num==1)
        return 0;
    int ans1 = 1+f(num-1);
    int ans2 =INT_MAX;
    int ans3 = INT_MAX;
    if(num%2==0)
        ans2 = 1+f(num/2);
    if(num%3==0)
        ans3 = 1+f(num/3);
    return min(ans1,min(ans2,ans3));
}
int ftd(int num)
{
    if(num==1)
        return 0;
    if(dp[num]!=-1)
        return dp[num];
    int ans1 = 1+ftd(num-1);
    int ans2 =INT_MAX;
    int ans3 = INT_MAX;
    if(num%2==0)
        ans2 = 1+ftd(num/2);
    if(num%3==0)
        ans3 = 1+ftd(num/3);
    return dp[num] = min(ans1,min(ans2,ans3));
}
int fbu(int num){
dp.clear();
dp[0] = 0;
dp[1] = 0;
dp[2] = 1;
dp[3] = 1;
for(int i=4;i<=num;i++){
    int ans1 = 1+dp[i-1];
    int ans2 = INT_MAX;
    int ans3 = INT_MAX;
    if(i%2==0)
        ans2 = 1+dp[i/2];
    if(i%3==0)
        ans3 = 1+dp[i/3];

    dp[i] = min(ans1,min(ans2,ans3));
}
return dp[num];
}
int main()
{
    cout<<fbu(10);
}
