#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    n => n / 3 if(n % 3 == 0)
    n => n / 2 if(n % 2 == 0)
    n => n - 1 
*/
// Bottom up approach

int minStepsBU(int n) {
    int dp[n + 1] = {0};
    dp[2] = 1;
    int mx = INT_MAX;
    for(int i = 3; i <= n; i++) {
        int x = i % 3 == 0 ? dp[i / 3] : mx;
        int y = i % 2 == 0 ? dp[i / 2] : mx;
        int z = dp[i - 1];
        // cout << x << " " << y << " " <<  z << endl;
        int ans = min({x, y, z});
        dp[i] = ans + 1;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    return dp[n];
}

// Top Down Approach
int minSteps(int n, int dp[]) {
    // base case
    if(n == 1)
        return 0;
    if(dp[n] != 0) {
        return dp[n];
    }

    // compute if dp[n] is not known (for first)
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if(n % 3 == 0) {
        op1 = minSteps(n / 3, dp) + 1;
    }
    if(n % 2 == 0) {
        op2 = minSteps(n / 2, dp)  + 1;
    }
    op3 = minSteps(n - 1, dp) + 1;
    int ans = min({op1, op2, op3});
    return dp[n] = ans;
}

signed main() {
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << minStepsBU(n) << endl;
    cout << minSteps(n, dp) << endl;
}