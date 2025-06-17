#include <iostream>
#include<vector>
#define mod 1000000007
using namespace std;
vector<long long> dp(1000,-1);
int f(int n)
{
    if(n==0)
    return 1;
    int count = 0;
    for(int i=1; i<=6; i++)
    {
        if(i>n)
            break;
        count+=f(n-i);
    }
    return count;
}
long long ftd(int n)
{
    if(n==0)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    long long count = 0;
    for(int i=1; i<=6; i++)
    {
        if(i>n)
         break;
        count = (count % mod + ftd(n-i) % mod) % mod;
    }
    return dp[n] = count%mod;
}
long long fbu(int n){
    dp.clear();
    dp[0] = 1;
for(int i=1;i<=n;i++){
    long long count = 0;
    for(int j=1;j<=6;j++){
        if(j>i)
        break;
    count = (count % mod + dp[i-j] % mod) % mod;
    }
    dp[i] = count;
}
return dp[n]%mod;
}
int main()
{
    int n;
    cin>>n;
    cout<<fbu(n);
    return 0;
}
