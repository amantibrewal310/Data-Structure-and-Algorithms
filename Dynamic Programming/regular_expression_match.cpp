#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];

bool solve(string &s, string &t, int i, int j) {
  int n = s.length();
  int m = t.length();

  if (j == m) {
    if (i == n) return true;
    if (s[i] != '*') return false;
    int k = i;
    while (s[k] == s[i]) {
      k++;
    }
    if (k == n) return true;
    return false;
  }
  if (i == n) return false;

  if (dp[i][j] != -1) return dp[i][j];

  if (s[i] == t[j]) {
    return dp[i][j] = solve(s, t, i + 1, j + 1);
  } else if (s[i] == '?') {
    return dp[i][j] = solve(s, t, i + 1, j + 1);
  } else if (s[i] == '*') {
    return dp[i][j] = solve(s, t, i + 1, j) or solve(s, t, i, j + 1);
  }
  return dp[i][j] = false;
}

signed main() {
  string s, t;
  cin >> s >> t;
  cout << solve(t, s, 0, 0) << endl;
}