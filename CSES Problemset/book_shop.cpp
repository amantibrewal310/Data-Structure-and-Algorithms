#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, vector<int> &pages, int budget) {
    int n = prices.size();
    int dp[n + 1][budget + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= budget; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (prices[i - 1] <= j) {
                dp[i][j] = max(pages[i - 1] + dp[i - 1][j - prices[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][budget];
}

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);

    for (auto &price : prices) {
        cin >> price;
    }
    for (auto &page : pages) {
        cin >> page;
    }
    cout << solve(prices, pages, x) << endl;
}