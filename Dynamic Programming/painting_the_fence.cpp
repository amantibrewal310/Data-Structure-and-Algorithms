#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;
int dp[100007][101];

int solve(int n, int k) {
    if(n == 0)
        return 0;
    if(n == 1)
        return k;
    if(n == 2)
        return dp[n][k] = k + k * (k - 1);
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = (solve(n - 2, k) % mod + solve(n - 1, k) % mod) % mod;
    ans *= (k - 1) % mod;
    ans %= mod;

    return dp[n][k] = ans;    
}

signed main() {
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}