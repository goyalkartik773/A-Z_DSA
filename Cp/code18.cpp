#include <bits/stdc++.h>
using namespace std;

long long smallestMissingLessThanK(const vector<int> &a, int k)
{
    if (k == 0)
        return 0;
    vector<bool> present(k, false);
    for (int x : a)
    {
        if (0 <= x && x < k)
            present[x] = true;
    }
    long long countMissing = 0;
    for (int i = 0; i < k; ++i)
        if (!present[i])
            countMissing++;

    return countMissing;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];

        long long missing = smallestMissingLessThanK(arr, k);
        long long cntK = 0;
        for (int x : arr)
        {
            if (x == k)
                cntK++;
        }
        cout << max(missing, cntK) << '\n';
    }
    return 0;
}
