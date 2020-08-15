#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    Given the prices of wines are given we can sell only extreme last or first pieces of wine.

    Prices of wines inc every year
    yth year = p[i] * y 

    find the maximum profit 
*/

int profit(vector<int> &prices, int i, int j, int y, int dp[][100]) {
    if(i > j) {
        return 0;
    }
    if(i == j) {
        return prices[i] * y;
    }
    if(dp[i][j] != 0)
        return dp[i][j];
    // Recursive Base
    int op1 = prices[i] * y + profit(prices, i + 1, j, y + 1, dp);
    int op2 = prices[j] * y + profit(prices, i, j - 1, y + 1, dp);
    return max(op1, op2);
}

signed main() {
    int n;
    cin >> n;
    vector<int> winesPrices(n);
    for(auto &price : winesPrices)
        cin >> price;
    int dp[100][100] = {0};
    cout << profit(winesPrices, 0, n - 1, 1, dp) << endl;
}