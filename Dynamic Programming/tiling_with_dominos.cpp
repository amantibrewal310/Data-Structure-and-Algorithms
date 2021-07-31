//?https://www.interviewbit.com/problems/tiling-with-dominoes/
#include <bits/stdc++.h>
using namespace std;

int go(int n) {
  const int mod = 1e9 + 7;

  int dp1[n + 1], dp2[n + 1];
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));

  dp1[0] = 1;
  dp2[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp1[i] = (dp1[i - 2] % mod + 2 * dp2[i - 1] % mod) % mod;
    dp2[i] = (dp1[i - 1] % mod + dp2[i - 2] % mod) % mod;
  }
  return dp1[n];
}

signed main() {
  int n;
  cin >> n;

  cout << go(n) << endl;
}