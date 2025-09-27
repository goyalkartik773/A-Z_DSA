#include<iostream>
#include<vector>
using namespace std;
int ways = 0;
void climb_stair(int total_stair,int stair){
// base case ()
    if(stair > total_stair)
    return;

    if(stair == total_stair)
    ways++;
    
climb_stair(total_stair,stair+1);
climb_stair(total_stair,stair+2);
}
int climb_stairs2(int total_stair,int stair,vector<int>& dp){
    if(stair>total_stair)
    return 0;
    if(stair == total_stair)
    return 1; // will remove the overlapping sub problem
    return  dp[stair] = climb_stairs2(total_stair,stair+1,dp) + climb_stairs2(total_stair,stair+2,dp);

}
int climb_stairs3(int total_stair,int stair,vector<int>& dp){
    dp[total_stair+1] = 0;
    dp[total_stair] = 1;
    for(stair=total_stair-1;stair>=0;stair--){
        dp[stair] = dp[stair+1]+dp[stair+2];
    }
    return dp[0];
}
int main(){
// recursion will take --> O(2^N) time complexity
// climb_stair(5,0);
// cout<<ways;

// top down dp approcah running time -->O(N) time complexity
vector<int> dp(7,0);

//  bottom up dp approcah running time -->O(N) time complexity
cout<<climb_stairs3(5,0,dp);
}