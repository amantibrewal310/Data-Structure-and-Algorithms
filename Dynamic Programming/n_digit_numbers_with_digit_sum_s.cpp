#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

vector<vector<int>> dp;

int go(int i, int n, int sum) {
  if (i == n and sum == 0) return 1;
  if (i >= n || sum < 0) return 0;

  if (dp[i][sum] != -1) return dp[i][sum];

  int ans = 0;

  for (int j = 0; j < 10; j++) {
    if (i == 0 and j == 0) continue;
    if (sum < j) break;
    ans = (ans % mod + go(i + 1, n, sum - j) % mod) % mod;
  }
  return dp[i][sum] = ans;
}

int solve(int A, int B) {
  // memset(dp, -1, sizeof(dp));
  dp.clear();
  dp.resize(A + 1, vector<int>(B + 1));

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      dp[i][j] = -1;
    }
  }

  return go(0, A, B);
}

signed main() {
  int n, s;
  cin >> n >> s;
  cout << solve(n, s) << endl;
}
