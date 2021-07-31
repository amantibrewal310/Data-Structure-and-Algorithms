#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &mat, int i, int k) {
  int n = mat.size();
  if (i >= n) return 0;
  if (k == 0) return 0;

  int op1 = max(mat[i][0] + mat[i][1], mat[i][1] + mat[i][2]) +
            solve(mat, i + 1, k - 1);
  int op2 = solve(mat, i + 1, k);

  if (i + 2 <= n) {
    for (int j = 0; j < 3; j++) {
    }
  }
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
}