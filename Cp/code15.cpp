#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < long long > f(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> f[i];
        }

        //  P aur S ke values ki frequency decide karna ---
        // Problem constraint F[1] >= N se, pivot k0 hamesha 1 hota hai.
        // Iska matlab S array hamesha [1, 1, ..., 1] hoga.
        vector < long long > count_p(n + 1, 0);
        vector < long long > count_s(n + 1, 0);

        count_s[1] = n;
        count_p[1] = f[1] - n;
        for (int i = 2; i <= n; ++i) {
            count_p[i] = f[i];
        }

        //  Frequency counts se P aur S arrays banana ---
        vector < int > p, s;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < count_p[i]; ++j) {
                p.push_back(i);
            }
            for (int j = 0; j < count_s[i]; ++j) {
                s.push_back(i);
            }
        }

        //  Sanity check S[i] <= P[i] ---
        for (int i = 0; i < n; ++i) {
            if (s[i] > p[i]) {
                cout << -1 << "\n";
                return;
            }
        }

        //  Original array A banane ki koshish karna ---
        vector < int > a(n);
        // Agar P[i] apne pichle element se bada hai, to A[i] ko P[i] hona hi padega.
        // Nahi to, hum sabse safe, choti value S[i] le lete hain.
        if (n > 0) {
            a[0] = p[0]; // Base case: A[0] must be P[0]
        }
        for (int i = 1; i < n; ++i) {
            if (p[i] > p[i - 1]) {
                a[i] = p[i];
            } else {
                a[i] = s[i];
            }
        }

        //  Check karna ki banaya hua A sahi hai ya nahi ---
        vector < int > p_check(n), s_check(n);
        if (n == 0) { // Edge case for N=0, although constraints say N>=1
            cout << "\n";
            return;
        }

        // Is A se Prefix Max array nikalte hain.
        p_check[0] = a[0];
        for (int i = 1; i < n; ++i) {
            p_check[i] = max(p_check[i - 1], a[i]);
        }

        // Is A se Suffix Min array nikalte hain.
        s_check[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            s_check[i] = min(s_check[i + 1], a[i]);
        }

        // Agar humare check arrays original P aur S se match karte hain,
        // to humara 'A' sahi hai.
        if (p_check == p && s_check == s) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            // Agar match nahi hua, to matlab koi solution possible nahi.
            cout << -1 << "\n";
        }
    }

    return 0;
}
