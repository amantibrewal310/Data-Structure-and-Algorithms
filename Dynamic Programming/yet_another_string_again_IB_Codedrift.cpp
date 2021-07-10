#include <bits/stdc++.h>
using namespace std;

int dp[1005][2];
int revCost[1005][1005];

int calculateRevCost(string &s, string &t, int i, int j) {
  if (i == j) return revCost[i][j] = (s[i] != t[j]);
  // if (j - i == 1) return revCost[i][j] = ;
  if (revCost[i][j] != -1) {
    return revCost[i][j];
  }
  int ans = (s[i] != t[j]) + (s[j] != t[i]);
  if (j - i >= 2) {
    ans += calculateRevCost(s, t, i + 1, j - 1);
  }
  return revCost[i][j] = ans;
}

int solve(string &s, string &t, int i, int k, int cost) {
  int n = s.length();
  if (i >= n) return 0;

  if (dp[i][k] != -1) return dp[i][k];

  if (s[i] == t[i]) {
    return dp[i][k] = solve(s, t, i + 1, k, cost);
  }
  int ans = 1 + solve(s, t, i + 1, k, cost);

  if (k > 0) {
    for (int j = i + 1; j < n; j++) {
      // cout << revCost[i][j] << endl;
      int tmp = cost + revCost[i][j];
      tmp += solve(s, t, j + 1, k - 1, cost);
      ans = min(ans, tmp);
    }
  }
  return dp[i][k] = ans;
}

signed main() {
  string s, t;
  // cin >> s >> t;
  s = "xxxxzzxyzxyzzzyzzyzxzyzxxyyyzxzzxxzxyxxzzxxzyyxyxyyxxzxzxzzyzx";
  t = "yyzzxyzyyzyxzyxyyyzyyzxzzzyzzxyzzyxzyxyyyxyxzxzyzzyzzyzzzxxzxz";
  int cost;
  // cin >> cost;
  cost = 8;
  memset(dp, -1, sizeof(dp));
  memset(revCost, -1, sizeof(revCost));
  // calculateRevCost(s, t, 0, s.length() - 1);
  int n = s.length();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      calculateRevCost(s, t, i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << revCost[i][j] << " ";
    }
    cout << endl;
  }
  cout << solve(s, t, 0, 1, cost);
}

// A : "xxxxzzxyzxyzzzyzzyzxzyzxxyyyzxzzxxzxyxxzzxxzyyxyxyyxxzxzxzzyzx"
// B : "yyzzxyzyyzyxzyxyyyzyyzxzzzyzzxyzzyxzyxyyyxyxzxzyzzyzzyzzzxxzxz"
// C : 8