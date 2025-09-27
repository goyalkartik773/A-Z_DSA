#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr)
{
    int n = arr.size();
    map<int,int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    vector<pair<int, int>> freqVec(mp.begin(), mp.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    int result = INT_MIN;
    int n1 = freqVec.size();
    for(int i = n1 - 1; i >= 0; i--)
    {
        int freq = freqVec[i].second;
        result = max(result, freq * (i + 1));
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << helper(arr) << endl;
    }
    return 0;
}
