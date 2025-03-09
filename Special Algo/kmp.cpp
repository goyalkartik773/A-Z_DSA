#include<iostream>
#include<vector>
using namespace std;
vector<int> longest_prefix_sum(string str){
    // return longest prefix sum // means return then idx length of equal prefix and suffix but not equal to size of the string
    int n = str.size();
    int pre=0;
    int suff=1;
    vector<int> lps(n,-1);
    lps[pre]=0;// one length ki string ka koi prefix suffix nahi hai
    while(suff<n){
        // step -- 1 condition 1
        if(str[pre]!=str[suff] && pre==0){
            lps[suff] = 0;
            suff++;
        }
        else if(str[pre]==str[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
        }
        else if(str[pre]!=str[suff] && pre!=0){
            pre = lps[pre-1];
        }
    }
    return lps;
}
int main(){
//So, the last value of the LPS array gives the length of the longest prefix that is also a suffix for the entire pattern, but not necessarily the longest "prefix and suffix" for the entire string in a more general sense.
string str = "ABCABDABCABCABD";
vector<int> lps = longest_prefix_sum(str);
for(auto ele:lps)
cout<<ele<<" ";

}