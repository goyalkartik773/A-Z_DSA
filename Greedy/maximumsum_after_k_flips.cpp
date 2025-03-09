#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int maxsum = INT_MIN;
int maximum_sum(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    // loop -1 t.c --> o(nlogn)
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    //o(klogn)
    while (k != 0)
    {
        int ele = pq.top(); // min ele is extracted
        pq.pop();
        if (ele == 0)
            break;
        ele = -1 * ele;
        pq.push(ele);
        k--;
    }
    int sum = 0;
    //o(nlogn)
    while (pq.size() != 0)
    {
        sum = sum + pq.top();
        pq.pop();
    }
   // t.c --> (O(nlogn));
    return sum;
}
// max_sum --> this is backtracking approach har array ki value ko flip kiya total possible solution mai jo best tha usse leleyia
// t.c --> o(n*2^k)
void max_sum(vector<int> arr,int k,int sum){
    if(k==0){
        sum = 0;
        for(auto ele :arr)
        sum  = sum + ele;
        maxsum = max(sum,maxsum);
        return;
    }
    for(int i =0;i<arr.size();i++){
        arr[i] = arr[i] * -1;
        max_sum(arr,k-1,sum);
        arr[i] = arr[i] * -1;
    }
}
int main()
{
    vector<int> arr = {2,3,4};
    max_sum(arr,2,0);
    cout<<maxsum;
}