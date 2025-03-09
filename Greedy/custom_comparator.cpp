#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool customcomparator(pair<int,int> a,pair<int,int> b){
    // mai vector ke pura pura pair ko sort karuga on my conditions
    if(a.first == b.first)
    return a.second < b.second;
    return a.first > b.first;
    // agar x cordinate equal hai to y coordinate increasing order mai sort hoge warna x coordinate to decreasing order mai hi sort hoge
}   
int main(){
    vector<pair<int,int>> arr = {{5,4},{1,2},{9,8},{-3,-4},{9,1}};
    sort(arr.begin(),arr.end(),customcomparator);
    for(auto ele:arr){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
}