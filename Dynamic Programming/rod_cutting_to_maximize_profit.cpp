#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int totalLen, int dp []) {
    if(totalLen == 0)
        return 0;
    
    if(dp[totalLen] != 0)
        return dp[totalLen];
    int best = 0;
    for(int len = 1; len <= totalLen; len++) {
        int netProfit = prices[len - 1] + maxProfit(prices, totalLen - len, dp);
        best = max(best, netProfit);
    }
    dp[totalLen] = best;
    return best;
}

signed main() {
    int n;
    cin >> n;
    vector<int> prices(n);

    for(auto &price : prices) {
        cin >> price;
    }
    int dp[n + 1] = {0};
    cout << maxProfit(prices, n, dp) << endl;

}