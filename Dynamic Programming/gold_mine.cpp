//?https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#
#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

bool isValid(int i, int j, int n, int m) {
  if (i >= 0 and i < n and j >= 0 and j < m) return true;
  return false;
}

int solve(vector<vector<int>> &mat, int i, int j) {
  int n = mat.size();
  int m = mat[0].size();

  if (!isValid(i, j, n, m)) return 0;
  if (j == m - 1) return mat[i][j];
  if (dp[i][j] != -1) return dp[i][j];
  // if(j == m - 1) return mat[i][j];

  int ans = 0;

  int dx[] = {+1, -1, 0};
  int dy[] = {+1, +1, +1};

  for (int k = 0; k < 3; k++) {
    int X = i + dx[k];
    int Y = j + dy[k];
    // cout << i << j << endl;
    int temp = mat[i][j] + solve(mat, X, Y);
    ans = max(ans, temp);
  }
  return dp[i][j] = ans;
}

int maxGold(int n, int m, vector<vector<int>> M) {
  // code here
  memset(dp, -1, sizeof(dp));
  int ans = solve(M, 0, 0);

  for (int i = 1; i < n; i++) {
    ans = max(ans, solve(M, i, 0));
  }
  return ans;
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  cout << maxGold(n, m, mat) << endl;
}

/*
 n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12

3 3
1 3 3
2 1 4
0 6 4



*/