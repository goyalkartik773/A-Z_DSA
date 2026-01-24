#include <bits/stdc++.h>
using namespace std;

char direction(pair<int,int> a, pair<int,int> b) {
    if (b.first == a.first + 1)
    return 'D';
    if (b.first == a.first - 1)
    return 'U';
    if (b.second == a.second + 1)
    return 'R';
    if (b.second == a.second - 1)
    return 'L';

    return 'X';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        long long m = (long long)n * n - k;

        if (m == 1) {
            cout << "NO"<<endl;
            continue;
        }

        cout << "YES"<<endl;

        vector<pair<int,int>> path;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                for (int j = 0; j < n; j++)
                path.push_back({i,j});
            else
                for (int j = n-1; j >= 0; j--)
                    path.push_back({i,j});
        }

        vector<string> grid(n, string(n, ' '));

        if (k > 0) {
            for (int i = k-1; i > 0; i--)
            grid[path[i].first][path[i].second] = direction(path[i], path[i-1]);
            grid[path[0].first][path[0].second] = 'L';
        }

        if (m > 0) {
            int idx = k;

            if (m % 2 != 0) {
                auto p1 = path[idx], p2 = path[idx+1], p3 = path[idx+2];
                grid[p1.first][p1.second] = direction(p1, p2);
                grid[p2.first][p2.second] = direction(p2, p3);
                grid[p3.first][p3.second] = direction(p3, p2);
                idx += 3;
            }

            while (idx < n*n) {
                auto p1 = path[idx], p2 = path[idx+1];
                grid[p1.first][p1.second] = direction(p1, p2);
                grid[p2.first][p2.second] = direction(p2, p1);
                idx += 2;
            }
        }

        for (int i = 0; i < n; i++)
        cout << grid[i] << endl;
    }

    return 0;
}
