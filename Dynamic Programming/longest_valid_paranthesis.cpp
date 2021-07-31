//?https://leetcode.com/problems/longest-valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

signed main() {
  string s;
  cin >> s;

  int n = s.length();
  int dp[n];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      dp[i] = 0;
      continue;
    }

    if (i - 1 >= 0 and s[i - 1] == '(') {
      dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
    } else if (i - 1 >= 0 and s[i - 1] == ')') {
      int j = i - dp[i - 1] - 1;

      if (j >= 0 and s[j] == '(') {
        dp[i] = dp[i - 1] + 2;
        if (j >= 1) {
          dp[i] += dp[j - 1];
        }
      }
    }
  }
  int ans = 0;

  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}

/*
()()))))()()(
*/