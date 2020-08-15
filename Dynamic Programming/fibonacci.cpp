#include<bits/stdc++.h>
using namespace std;

// Top Down Approach
int fib(int n, int dp[]) {
    if(n == 0 or n == 1)
        return n;
    if(dp[n] != 0)
        return dp[n];
    int ans;
    ans = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n] = ans;
}

// Bottom Up Approach
int fibBU(int n) {
    int dp[n + 1] = {0};
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibSpaceOpt(int n) {
    if(n == 0 or n == 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
signed main() {
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << fib(n, dp) << endl;
    // cout << dp[n] << endl;
    cout << fibBU(n) << endl;
    cout << fibSpaceOpt(n) << endl;
}