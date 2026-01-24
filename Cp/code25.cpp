#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_set<int> st;
        for(auto ele:arr){
            st.insert(ele);
        }
        int countDistinct = st.size();
        int result = 2*countDistinct - 1;
        cout<<result<<endl;
    }
}

