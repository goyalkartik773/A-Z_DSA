#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;
void combination_sum(vector<int> &arr,int idx,int target,vector<int>& subset)
{
    if(target == 0)
    {
        // subset mil gaya
        ans.push_back(subset);
        return;
    }
    if(idx == arr.size())
    return;
    if(arr[idx] <= target)
    {
        subset.push_back(arr[idx]);
        combination_sum(arr,idx+1,target-arr[idx],subset);
        subset.pop_back();
    }
    int j = idx + 1;
    while(j<arr.size() && (arr[j]==arr[j-1]))
    j++;
    combination_sum(arr,j,target,subset);
}
int main()
{
    vector<int> arr = {10,1,2,7,6,1,5};
    vector<int> subset;
    sort(arr.begin(),arr.end());
    combination_sum(arr,0,8,subset);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
