#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int m;
        cin >> n >> m;
        vector<long long> arr(m);
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }

        bool flag = true;
        if (m > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (arr[i + 1] != arr[i] + 1)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            long long result = n  + 1 - arr[m - 1];
            cout << result<< endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}
