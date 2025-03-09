#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customcomparator(pair<int, int> &a, pair<int, int> &b)
{
    // uss pair ko first per rakhna hai jiska value by weight ratio sabse jada hai
    double r1 = (double)a.first / a.second; // represents first pair
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int, int>> arr; // --> {val,weight}
for (int i = 0; i < wt.size(); i++)
{
    arr.push_back({val[i], wt[i]});
}
sort(arr.begin(), arr.end(), customcomparator);
int idx = 0;
double ans = 0;
for(int i=0;i<arr.size()&& capacity!=0;i++){
    pair<int, int> p = arr[i];
    double we = (double)p.second;
    double val = (double)p.first;
    if (we > capacity)
    {
        // take fraction of item;
        ans += (val / we) * capacity;
        capacity = 0;
        break;
    }
    else
    {
        ans = ans + val;
        capacity = capacity - we;
    }
    
}
return ans;
}
int main()
{
    vector<int> val = {60,100};
    vector<int> wt = {10,20};
    cout<<fractionalKnapsack(val,wt,50);
}