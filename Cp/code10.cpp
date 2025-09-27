#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<long long> a(m);
        set<long long> black;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            black.insert(a[i]);
        }
        // We'll keep track of all final cells visited to color
        vector<long long> to_color;
        for (int i = 0; i < n; ++i) {
            long long pos = 1;
            auto it = black.upper_bound(pos); // first black cell > pos
            int j = 0;
            while (j <= i) {
                if (s[j] == 'A') {
                    pos++;
                } else { // 'B'
                    // Jump to min y > pos, y is white
                    while (true) {
                        auto nxt_it = black.upper_bound(pos);
                        if (nxt_it == black.end() || *nxt_it != pos + 1) {
                            pos++;
                            break;
                        }
                        pos++;
                    }
                }
                ++j;
            }
            to_color.push_back(pos);
        }
        for (auto x : to_color) black.insert(x);
        vector<long long> result(black.begin(), black.end());
        cout << result.size() << '\n';
        for (auto cell : result) cout << cell << " ";
        cout << '\n';
    }
    return 0;
}
