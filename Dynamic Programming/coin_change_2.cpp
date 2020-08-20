//?https://practice.geeksforgeeks.org/problems/number-of-coins/0
#include<bits/stdc++.h>
using namespace std;

int dp[1000007];

int solve(vector<int> &coins, int value) {
    if(value == 0)
        return 0;
    if(dp[value] != 0)
        return dp[value];
    int best = INT_MAX;
    int flag = 0;
    for(auto coin : coins) {
        if(coin <= value) {
            int ans = solve(coins, value - coin);
            if(ans != -1) {
                flag = 1;
                best = min(best, ans + 1);
            }
        }
    }
    if(flag) {
        dp[value] = best;
    } else {
        dp[value] = -1;
    }
    return dp[value];
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int value;
        cin >> value;
        int n;
        cin >> n;
        vector<int> coins(n);
        for(auto &coin : coins) {
            cin >> coin;
        }

        memset(dp, 0, sizeof(dp));
        cout << solve(coins, value) << endl;
    }
}