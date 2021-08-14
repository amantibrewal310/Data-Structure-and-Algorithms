//?https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
  int x = a[0] * a[1];
  int y = b[0] * b[1];

  if (x == y) {
    if (a[0] == b[0]) {
      if (a[1] == b[1]) {
        return a[2] < b[2];
      }
      return a[1] < b[1];
    }
    return a[0] < b[0];
  }
  return x < y;
}
int dp[601][601];

int go(vector<vector<int>> &arr, int i, int prev) {
  int n = arr.size();
  if (i >= n) return 0;

  if (prev != -1 and dp[i][prev] != -1) return dp[i][prev];

  int ans = go(arr, i + 1, prev);

  if (prev == -1) {
    // cout << "i: " << i << endl;
    int op = arr[i][2] + go(arr, i + 1, i);
    ans = max(ans, op);
  } else if (arr[i][0] >= arr[prev][0] and arr[i][1] >= arr[prev][1] and
             arr[i][2] >= arr[prev][2]) {
    int op = arr[i][2] + go(arr, i + 1, i);
    ans = max(ans, op);
  }
  return prev != -1 ? dp[i][prev] = ans : ans;
}

int solve(vector<int> &l, vector<int> &h, vector<int> &w) {
  int n = l.size();
  vector<vector<int>> arr;

  for (int i = 0; i < n; i++) {
    set<vector<int>> st;

    st.insert({l[i], w[i], h[i]});
    st.insert({l[i], h[i], w[i]});
    st.insert({w[i], h[i], l[i]});
    st.insert({w[i], l[i], h[i]});
    st.insert({h[i], l[i], w[i]});
    st.insert({h[i], w[i], l[i]});
    for (auto ele : st) {
      arr.push_back(ele);
    }
  }
  sort(arr.begin(), arr.end(), cmp);

  memset(dp, -1, sizeof(dp));
  return go(arr, 0, -1);
}

signed main() {
  int n;
  cin >> n;
  vector<int> l(n), h(n), w(n);

  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << solve(l, h, w) << endl;
}

/*
4
4 1 4 10
6 2 5 12
7 3 6 32

*/