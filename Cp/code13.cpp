#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    vector<int> arr(x+y,0);
	    for(int i=0;i<x;i++){
	        arr[i] = 1;
	    }
	    for(int i=0;i<y;i++){
	        arr[i+x] = 2;
	    }
	    unordered_set<int> st;
	    int i = 0;
	    int j = x + y -1;
	    int result = 0;
	    while(i <= j){
	        if(st.find(i)!=st.end() && st.find(i+1)!=st.end() && st.find(j)!=st.end())
	        result += max(arr[i],max(arr[i+1],arr[j]));

	         i+=2;
	         j+=1;
	    }
	    cout<<result<<endl;
	}

}

