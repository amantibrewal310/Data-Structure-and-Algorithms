#include<bits/stdc++.h>
using namespace std;
// #define int long long

//Top Down Approach

int coinChange(vector<int>& coins, int amount, int dp[]) {
    if (amount == 0)
        return 0;
    if (dp[amount] != 0)
        return dp[amount];
    int ans = INT_MAX;
    bool flag = 0;
    for (auto coin : coins) {
        if (amount - coin >= 0) {
            int subproblem = coinChange(coins, amount - coin, dp);
            if (subproblem != -1) {
                flag = 1;
                ans = min(ans, subproblem + 1);
            }
        }
    }
    if (flag) {
        dp[amount] = ans;
    }
    else {
        dp[amount] = -1;
    }
    return dp[amount];
}

// Bottom Up Approach

int coinChangeBU(vector<int>& coins, int amount) {
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= amount; i++) {
        int ans = INT_MAX;
        bool flag = 0;
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 and dp[i - coins[j]] != -1) {
                flag = 1;
                ans = min(ans, dp[i - coins[j]] + 1);
            }
        }
        if (flag == 0)
            dp[i] = -1;
        else
            dp[i] = ans;
    }
    return dp[amount];

}

signed main() {
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    vector<int> coins(n);
    for(auto &coin : coins)
        cin >> coin;
    int dp[100] = {0};
    cout << coinChange(coins, amount, dp) << endl;
    cout << coinChangeBU(coins, amount) << endl;
    

}