//?https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
#include<bits/stdc++.h>
using namespace std;

int dp[11][51];

int solve(int e, int f) {
    if(f == 0 or f == 1)
        return f;
    
    if(e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    
    int mn = INT_MAX;
    for(int k = 1; k <= f; k++) {
        int tmp = max(solve(e - 1, k - 1), solve(e, f - k)) + 1;
        mn = min(mn, tmp);
    }
    return dp[e][f] = mn;
}

signed main() {

    int t;
    cin >> t;
    while(t--) {
        int e, f;
        cin >> e >> f;
        memset(dp, -1, sizeof(dp));
        cout << solve(e, f) << endl;
    }

}