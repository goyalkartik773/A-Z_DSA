#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string str;
        str.reserve(n);
        for (int i = 0; i < n; ++i) {
            char ch;
            cin >> ch;
            str += ch;
        }

        vector<int> zeros(n + 1, 0);
        vector<int> ones(n + 1, 0);
        vector<int> zeroPairs(n + 1, 0);
        vector<int> onePairs(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (str[i] == '0')
            zeros[i + 1] = zeros[i] + 1;
            else
            zeros[i + 1] = zeros[i];

            if (str[i] == '1')
            ones[i + 1] = ones[i] + 1;
            else
            ones[i + 1] = ones[i];

            if (i > 0) {
                if (str[i] == '0' && str[i - 1] == '0')
                    zeroPairs[i + 1] = zeroPairs[i] + 1;
                else
                    zeroPairs[i + 1] = zeroPairs[i];

                if (str[i] == '1' && str[i - 1] == '1')
                    onePairs[i + 1] = onePairs[i] + 1;
                else
                     onePairs[i + 1] = onePairs[i];
            } else {
                zeroPairs[i + 1] = 0;
                onePairs[i + 1] = 0;
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;

            int totalZeros = zeros[r] - zeros[l - 1];
            int totalOnes = ones[r] - ones[l - 1];

            int totalZeroPairs = 0;
            int totalOnePairs = 0;
            if (l != r) {
                totalZeroPairs = zeroPairs[r] - zeroPairs[l];
                totalOnePairs = onePairs[r] - onePairs[l];
            }

            if (totalZeros % 3 != 0 || totalOnes % 3 != 0) {
                cout << -1 << endl;
            } else {
                long long groupsZero = totalZeros / 3;
                long long groupsOne = totalOnes / 3;

                long long costOptionA;
                if (totalZeroPairs >= groupsZero) {
                    costOptionA = groupsZero;
                } else {
                    costOptionA = totalZeroPairs + (groupsZero - totalZeroPairs) * 2;
                }
                long long costOptionA_1 = groupsOne;
                long long totalCostA = costOptionA + costOptionA_1;

                long long costOptionB;
                if (totalOnePairs >= groupsOne) {
                    costOptionB = groupsOne;
                } else {
                    costOptionB = totalOnePairs + (groupsOne - totalOnePairs) * 2;
                }
                long long costOptionB_1 = groupsZero;
                long long totalCostB = costOptionB + costOptionB_1;

                if (totalCostA < totalCostB)
                cout << totalCostA << endl;
                else cout << totalCostB << endl;
            }
        }
    }

    return 0;
}
