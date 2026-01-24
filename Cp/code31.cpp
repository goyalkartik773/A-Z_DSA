#include <bits/stdc++.h>
using namespace std;

int helper(int start, int n,vector<int>& a) {
    vector<int> c(n);
    c[0] = start;

    for (int i = 0; i < n - 1; i++) {
        long long diff = a[i + 1] - a[i];
        long long next = 1 - diff - c[i];
        if (next < 0 || next > 1)
        return 0;
        c[i + 1] = next;
    }

    long long totalR = accumulate(c.begin(), c.end(), 0LL);
    long long visible = (1 - c[0]) + totalR;

    return visible == a[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0;i<n;i++)
        cin >> arr[i];

        long long res = helper(0, n, arr) + helper(1, n, arr);
        cout << res % 676767677 << "\n";
    }
}
