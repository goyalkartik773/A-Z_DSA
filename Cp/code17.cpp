#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int result = INT_MIN;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i+=2){
         result = max(result,abs(arr[i]-arr[i+1]));
        }
        cout<<result<<endl;
    }

}
