#include<bits/stdc++.h>
using namespace std;
int dp[101][101];

int solveTD(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    
    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));
    int res = 0;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int solve(string &s, string &t, int n, int m, int cnt) {
    if(n == 0 or m == 0)
        return cnt;
    if(s[n - 1] == t[m - 1]) {
        cnt = solve(s, t, n - 1, m - 1, cnt + 1);
    }
    cnt = max({cnt, solve(s, t, n - 1, m, 0), solve(s, t, n, m - 1, 0)});
    return cnt;
}


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        memset(dp, -1, sizeof(dp));
        cout << solve(s, t, n, m, 0) << endl;

    }
}