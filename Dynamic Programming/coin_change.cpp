//?https: //practice.geeksforgeeks.org/problems/coin-change/0
#include <bits/stdc++.h>
using namespace std;
int dp[305][305];

int solve(vector<int> &coins, int i, int amount) {
  if (amount == 0) return 1;
  if (i >= coins.size()) {
    return 0;
  }

  if (dp[i][amount] != -1) {
    return dp[i][amount];
  }

  if (coins[i] <= amount) {
    int op1 = solve(coins, i, amount - coins[i]);
    int op2 = solve(coins, i + 1, amount);

    dp[i][amount] = op1 + op2;
  } else {
    dp[i][amount] = solve(coins, i + 1, amount);
  }
  return dp[i][amount];
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;
    int amount;
    cin >> amount;
    memset(dp, -1, sizeof(dp));
    cout << solve(coins, 0, amount) << endl;
  }
}