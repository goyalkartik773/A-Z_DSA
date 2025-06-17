#include <iostream>
#include<climits>
using namespace std;
int helper(int n){
 // vector<int> digits;
  int ans = INT_MIN;
  while(n!=0){
    ans = max(ans,n%10);
    n=n/10;
  }
  return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    while(n!=0){
      int x = helper(n); // find the maximum digit from n
      n=n-x;
      ans++;
    }
    cout<<ans;
}
