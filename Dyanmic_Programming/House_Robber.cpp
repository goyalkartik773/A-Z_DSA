#include<iostream>
#include<vector>
using namespace std;
vector<int> dp(1000,-1);
int f(vector<int>& arr,int idx){
    // this funcion gives the maximum amount of money that can be robbed from idx house to the last house
    if(idx >= arr.size())
        return 0; // base case agr apka house exist hi nahi karta to waha zero money hi robbed hogi naa
    return max((arr[idx]+f(arr,idx+2)),(0+f(arr,idx+1)));
}
int ftd(vector<int>& arr,int idx){
    // this funcion gives the maximum amount of money that can be robbed from idx house to the last house
    if(idx >= arr.size())
        return 0; // base case agr apka house exist hi nahi karta to waha zero money hi robbed hogi naa
    if(dp[idx]!=-1)
        return dp[idx];
    return dp[idx]= max((arr[idx]+f(arr,idx+2)),(0+f(arr,idx+1)));
}
int fbu(vector<int>& arr){
    dp.clear();
    int n = arr.size();
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max((arr[i]+dp[i-2]),dp[i-1]);
    }
    return dp[n-1];
}
int main(){
vector<int> arr = {1,2,3,1};
cout<<fbu(arr);
}
