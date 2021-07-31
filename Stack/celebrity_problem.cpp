#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> &mat) {
  int n = mat.size();
  int cele = 0;  // assuming celebrity is zero

  for (int i = 1; i < n; i++) {
    if (mat[cele][i] == 1) {
      cele = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != cele and (mat[cele][i] == 1 or mat[i][cele] == 0)) return -1;
  }
  return cele;
}

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  cout << findCelebrity(mat) << endl;
}