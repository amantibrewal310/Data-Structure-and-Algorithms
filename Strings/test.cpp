#include <bits/stdc++.h>
using namespace std;

vector<int> kadane(vector<int> &nums, int k) {
  int n = nums.size();

  int mx = INT_MIN;
  int len = INT_MAX;

  int start = 0;
  int curr = 0;

  for (int i = 0; i < n; i++) {
    curr += nums[i];
    if (curr == k) {
      int temp = i - start + 1;
      len = min(len, temp);
      mx = k;
    }

    while (curr > k) {
      curr -= nums[start];
      start++;
    }
  }
  return {mx, len};
}

int gardenHire2020(vector<int> x, vector<int> y, int k) {
  int n = x.size();

  vector<vector<int>> mat(101, vector<int>(101, 0));

  for (int i = 0; i < n; i++) {
    mat[x[i]][y[i]] = 1;
  }
  int res = INT_MAX;
  for (int i = 0; i < 101; i++) {
    vector<int> ans(101);
    for (int j = i; j < 101; j++) {
      for (int col = 0; col < 101; col++) {
        ans[col] += mat[j][col];
      }
      auto p = kadane(ans, k);

      if (p[0] == k) {
        int l = p[1];
        int b = j - i + 1;
        cout << l << " " << b << endl;
        int per = 2 * (l + b);
        res = min(res, per);
      }
    }
  }
  return res;
}

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  cout << gardenHire2020(x, y, k);
}