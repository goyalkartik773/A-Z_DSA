#include <iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int> dp;
vector<int> helper(int n){
 vector<int> digits;
  while(n!=0){
    if(n%10>0)
    digits.push_back(n%10);
    n=n/10;
  }
  return digits;
}
int f(int num){
if(num==0)
return 0;
if(num<10)
return 1;
vector<int> digits = helper(num);
int ans = INT_MAX;
for(int i=0;i<digits.size();i++){
    ans = min(ans,1+f(num-digits[i]));
}
return ans;
}
int ftd(int num){
if(num==0)
return 0;
if(num<10)
return 1;
if(dp[num]!=-1)
return dp[num];
vector<int> digits = helper(num);
int ans = INT_MAX;
for(int i=0;i<digits.size();i++){
    ans = min(ans,1+ftd(num-digits[i]));
}
return dp[num] = ans;
}
int fbu(int num){
    dp.clear();
    dp[0] = 0;
    for(int i=1;i<10;i++)
    dp[i] = 1;
    for(int i=10;i<=num;i++){
     vector<int> digits = helper(i);
        int ans = INT_MAX;
        for(int j=0;j<digits.size();j++){
            ans = min(ans,1+dp[i-digits[j]]);
        }
        dp[i] = ans;
    }
    return dp[num];
}
int main()
{
    int n;
    cin>>n;
    dp.resize(n + 1, -1);
    cout<<f(n);
}
