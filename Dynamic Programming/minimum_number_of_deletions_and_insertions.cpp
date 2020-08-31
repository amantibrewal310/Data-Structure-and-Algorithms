//?https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
#include<bits/stdc++.h>
using namespace std;

int lcsLen(string s, string t) {
    int n = s.length();
    int m = t.length();
    
    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[n][m];
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        
        int lcsLength = lcsLen(s, t);
        
        int ans = (n - lcsLength) + (m - lcsLength);
        cout << ans << endl;
        
    }
}