#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> zeros;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zeros.push_back(i);
            }
        }

        bool flag = true;
        if (zeros.size()!=0) {
            vector<bool> cl(n, false);
            vector<bool> cr(n, false);
            for (int z_idx : zeros) {
                cl[z_idx] = (z_idx == 0) || (s[z_idx - 1] == '0') || (z_idx > 1 && s[z_idx - 1] == '1' && s[z_idx - 2] == '0');
                cr[z_idx] = (z_idx == n - 1) || (s[z_idx + 1] == '0') || (z_idx + 2 < n && s[z_idx + 1] == '1' && s[z_idx + 2] == '0');
            }

            int m = zeros.size();
            int i = 0;
            while (i < m) {
                int j = i;
                while (j + 1 < m && zeros[j + 1] == zeros[j] + 2 && s[zeros[j] + 1] == '1') {
                    j++;
                }

                int start_pos = zeros[i];
                bool cur_l = cl[start_pos];
                bool cur_r = cr[start_pos];

                if (!cur_l && !cur_r) {
                    flag = false;
                    break;
                }

                for (int k = i + 1; k <= j; ++k) {
                    int current_zero_idx = zeros[k];

                    bool nxt_l = false;
                    bool nxt_r = false;

                    if (cur_r && cl[current_zero_idx]) {
                        nxt_l = true;
                    }
                    if (cur_l && cr[current_zero_idx]) {
                        nxt_r = true;
                    }

                    cur_l = nxt_l;
                    cur_r = nxt_r;

                    if (!cur_l && !cur_r) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) {
                    break;
                }
                i = j + 1;
            }
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
