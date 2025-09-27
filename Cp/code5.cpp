#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> sets(n);
        vector<int> freq(m + 1, 0);

        for (int i = 0; i < n; i++) {
            int li;
            cin >> li;
            sets[i].resize(li);
            for (int j = 0; j < li; j++) {
                cin >> sets[i][j];
                freq[sets[i][j]]++;
            }
        }

        // Check if any number from 1 to m is missing (freq == 0)
        bool glflag = false;
        for (int i = 1; i <= m; i++) {
            if (freq[i] == 0) {
                cout << "NO\n";
                glflag = true;
                break;
            }
        }
        if (glflag)
            continue;

        // Find sets that contain at least one unique number (cannot skip these sets)
        vector<bool> cannotSkip(n, false);
        for (int i = 0; i < n; i++) {
            for (int x : sets[i]) {
                if (freq[x] == 1) {
                    cannotSkip[i] = true;
                    break;
                }
            }
        }

        int cannotSkipCount = 0;
        for (bool val : cannotSkip) {
            if (val)
                cannotSkipCount++;
        }
        int optionalCount = n - cannotSkipCount;

        if (optionalCount >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
