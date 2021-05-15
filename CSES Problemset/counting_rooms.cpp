#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 and i < n and j >= 0 and j < m) {
        return true;
    }
    return false;
}

void dfs(vector<string> &mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();

    if (!isValid(i, j, n, m)) {
        return;
    }
    if (mat[i][j] == '#') {
        return;
    }
    mat[i][j] = '#';
    dfs(mat, i - 1, j);
    dfs(mat, i, j + 1);
    dfs(mat, i + 1, j);
    dfs(mat, i, j - 1);
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                dfs(mat, i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}