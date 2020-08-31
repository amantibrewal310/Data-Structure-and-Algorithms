//?https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
#include<bits/stdc++.h>
using namespace std;

int lcsLen(string s, string t) {
    int m = s.length();
    int n = t.length();
    
    int dp[m + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++)  {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        
        int ans = s.length() + t.length() - lcsLen(s, t);
        cout << ans << endl;
    }
}