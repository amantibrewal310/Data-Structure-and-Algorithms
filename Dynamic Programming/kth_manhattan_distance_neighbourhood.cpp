//?https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
#include <bits/stdc++.h>
using namespace std;

int dp[301][301][301];

bool isValid(int i, int j, int n, int m) {
  if (i >= 0 and i < n and j >= 0 and j < m) return true;
  return false;
}

int solve(vector<vector<int>> &mat, int i, int j, int k) {
  int n = mat.size();
  int m = mat[0].size();

  if (k == 0) return dp[i][j][k] = mat[i][j];

  if (dp[i][j][k] != -1) return dp[i][j][k];

  int ans = mat[i][j];

  int dx[] = {+1, -1, 0, 0};
  int dy[] = {0, 0, +1, -1};

  for (int l = 0; l < 4; l++) {
    int X = i + dx[l];
    int Y = j + dy[l];

    if (!isValid(X, Y, n, m)) continue;
    ans = max(ans, solve(mat, X, Y, k - 1));
  }
  return dp[i][j][k] = ans;
}

signed main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> mat(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  vector<vector<int>> res(n, vector<int>(m, 0));
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res[i][j] = solve(mat, i, j, k);
    }
  }
  // cout << solve(mat, 0, 0, 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}