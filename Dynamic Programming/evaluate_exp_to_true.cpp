//?https://www.interviewbit.com/problems/evaluate-expression-to-true/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e3 + 3;
int dp[151][151][2];

int solve(string &s, int i, int j, bool isTrue) {
  if (i > j) return 0;
  if (i == j) {
    if (isTrue)
      return s[i] == 'T';
    else
      return s[i] == 'F';
  }

  if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
  int ans = 0;

  for (int k = i; k < j; k++) {
    if (s[k] == 'T' or s[k] == 'F') continue;
    int leftTrue = solve(s, i, k - 1, true);
    int leftFalse = solve(s, i, k - 1, false);
    int rightTrue = solve(s, k + 1, j, true);
    int rightFalse = solve(s, k + 1, j, false);

    if (s[k] == '|') {
      if (isTrue) {
        ans = (ans % mod + (leftTrue * rightTrue + leftTrue * rightFalse +
                            leftFalse * rightTrue)) %
              mod;
      } else {
        ans = (ans % mod + (leftFalse * rightFalse)) % mod;
      }
    } else if (s[k] == '^') {
      if (isTrue) {
        ans =
            (ans % mod + ((leftTrue * rightFalse) + (leftFalse * rightTrue))) %
            mod;
      } else {
        ans =
            (ans % mod + (leftTrue * rightTrue + leftFalse * rightFalse)) % mod;
      }
    } else if (s[k] == '&') {
      if (isTrue) {
        ans = (ans % mod + (leftTrue * rightTrue)) % mod;
      } else {
        ans = (ans % mod + (leftTrue * rightFalse + leftFalse * rightTrue +
                            leftFalse * rightFalse)) %
              mod;
      }
    }
  }
  return dp[i][j][isTrue] = ans;
}

signed main() {
  string s;
  cin >> s;
  memset(dp, -1, sizeof(dp));
  cout << solve(s, 0, s.length() - 1, true) << endl;
}