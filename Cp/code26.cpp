#include <bits/stdc++.h>
using namespace std;

int cheb(int r1, int c1, int r2, int c2) {
    return max(abs(r1 - r2), abs(c1 - c2));
}

int checkBound(int x, int L, int R) {
    return max(L, min(x, R));
}

int farthestKrugh(int n, int rK, int cK, int rD, int cD, int t) {
    vector<pair<int,int>> points;
    points.push_back({checkBound(rK + t, 0, n), cK});
    points.push_back({checkBound(rK - t, 0, n), cK});
    points.push_back({rK, checkBound(cK + t, 0, n)});
    points.push_back({rK, checkBound(cK - t, 0, n)});

    for (int i : {0, n}) {
        for (int j : {0, n}) {
            if (abs(i - rK) + abs(j - cK) <= t)
                points.push_back({i, j});
        }
    }

    int best = 0;
    for (auto p : points) {
        int r = p.first, c = p.second;
        if (r < 0 || r > n || c < 0 || c > n)
        continue;
        if (abs(r - rK) + abs(c - cK) <= t) {
            best = max(best, cheb(r, c, rD, cD));
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;
        int lo = 0, hi = n + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (farthestKrugh(n,rk,ck,rd,cd, mid) <= mid)
            hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
    return 0;
}
