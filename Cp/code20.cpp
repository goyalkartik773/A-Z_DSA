#include <bits/stdc++.h>
using namespace std;

vector<int> lastKIdx(int n, vector<int> &arr, int target) {
    vector<int> endIdx(n);
    unordered_map<int, int> freq;
    int right = 0;

    for (int i = 0; i < n; i++) {

        while (right < n && (int)freq.size() < target) {
            freq[arr[right]]++;
            right++;
        }

        if ((int)freq.size() == target) {
            endIdx[i] = right - 1;
        } else {
            endIdx[i] = n;
        }

        freq[arr[i]]--;
        if (freq[arr[i]] == 0) {
            freq.erase(arr[i]);
        }
    }
    return endIdx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> endK = lastKIdx(n, arr, k);
        vector<int> endK1 = lastKIdx(n, arr, k + 1);

        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (endK[i] == n)
            continue;

            long long leftMost = endK[i];
            long long rightMost = endK1[i] - 1;

            long long minLen = (long long)i + l - 1;
            long long maxLen = (long long)i + r - 1;

            long long cStart = max(leftMost, minLen);
            long long cEnd = min(rightMost, maxLen);

            if (cEnd >= cStart) {
                result += (cEnd - cStart + 1);
            }
        }

        cout << result << endl;
    }

}
