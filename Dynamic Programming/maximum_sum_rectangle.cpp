//?https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

#include <bits/stdc++.h>
using namespace std;

// Brute Force

int solve(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  int res = 0;

  for (int r1 = 0; r1 < n; r1++) {
    for (int c1 = 0; c1 < m; c1++) {
      for (int r2 = r1; r2 < n; r2++) {
        for (int c2 = c1; c2 < m; c2++) {
          int sum = 0;
          for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
              sum += mat[i][j];
            }
          }
          res = max(res, sum);
        }
      }
    }
  }
  return res;
}

signed main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int>> mat(row, vector<int>(col));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> mat[i][j];
    }
  }

   cout << solve(mat) << endl;
}

/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

*/