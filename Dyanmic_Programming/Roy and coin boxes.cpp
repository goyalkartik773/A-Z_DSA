#include<iostream>
#include<vector>
using namespace std;
// This code calculates the number of boxes that have at least 'x' coins after performing 'm' queries of adding coins to ranges [l, r].
// method 1 using twoo vectors left and right to store the number of coins added at each index
// method 2 using line sweep  technique to calculate the number of coins in each box after all querie
int main()
{
    // method 1 dp approach
    // int n;
    // cin>>n;
    // int m;
    // cin>>m;
    // vector<int> left(1000000,0);
    // vector<int> right(1000000,0);
    // for(int i=0;i<m;i++){
    //     int l,r;
    //     cin>>l>>r;
    //     left[l]+=1;
    //     right[r]+=1;
    // }
    // vector<int> arr(1000000,0);
    // arr[1] = left[1]; // box1 utni baar effect hua jitni baar left query 1 ayi hogi
    // for(int i=2;i<=n;i++){
    //     arr[i] = left[i] + arr[i-1] - right[i-1];
    // }
    // // arr[i] will tell no of coins in ith box after m days [l,r] coins add hua hoga
    // vector<int> ans(1000000,0);
    // for(int i=1;i<=n;i++){
    //     ans[arr[i]]+=1;
    // }
    // // ith coins exactly kitne boxes mai hai
    // // suffix sum will tell atleast ith coins kitne boxes mai hai
    // for(int i=n-1;i>0;i--){
    //     ans[i] = ans[i] + ans[i+1];
    // }
    // int q;
    // cin>>q;
    // for(int i=0;i<q;i++){
    //     int x;
    //     cin>>x;
    //     cout<<ans[x]<<endl;
    // }

    // This code uses the line sweep technique to efficiently calculate the number of coins in each box after performing 'm' queries.
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> arr(1000001,0);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        arr[l] += 1; // adding 1 coin to the left index
        arr[r+1] -= 1; // removing 1 coin from the right index + 1
    }
    // line sweep technique
    for(int i=1;i<=n;i++){
        arr[i] = arr[i] + arr[i-1]; // calculating the prefix sum to get the total coins in each box
    }
    // now arr[i] will tell how many coins are there in the ith box after all queries
    vector<int> ans(1000001,0);
    for(int i=1;i<=n;i++){
        ans[arr[i]]+=1;
    }
    // ans[i] will tell how many boxes have exactly i coins
    // now we need to calculate how many boxes have at least i coins
    for(int i=n-1;i>0;i--){
        ans[i] = ans[i] + ans[i+1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }

}