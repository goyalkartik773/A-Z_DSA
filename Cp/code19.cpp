#include <bits/stdc++.h>
using namespace std;

long long minSwaps(string& s, char ch)
{
    // Is vector me hum target character ke saare indices (posArr) ko store karenge
    vector<int> posArr;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ch)
        {
            posArr.push_back(i);
        }
    }

    if (posArr.size() <= 1)
    {
        return 0;
    }

    vector<long long> brr;
    for (int i = 0; i < posArr.size(); i++)
    {
        brr.push_back((long long)posArr[i] - i);
    }
    int n = brr.size();
    long long median = brr[n / 2];

    long long totalOperation = 0;
    for (auto val : brr)
    {
        totalOperation += abs(val - median);
    }

    return totalOperation;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        long long aOperations = minSwaps(str,'a');
        long long bOperations = minSwaps(str,'b');

        cout << min(aOperations, bOperations) << endl;
    }

    return 0;
}
