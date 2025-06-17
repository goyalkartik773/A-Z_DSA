#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void f(int row, int prev_col, int n, int m, int sum, vector<vector<int>> &arr) {
    if (row == n) {
        ans = max(ans, sum);
        return;
    }
    for (int j = 0; j < m; j++) {
        if (j != prev_col) {
            f(row + 1, j, n, m, sum + arr[row][j], arr);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    f(0, -1, n, m, 0, arr);
    cout << ans << endl;
    return 0;
}
