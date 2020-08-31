#include<bits/stdc++.h>
using namespace std;

string findLCS(string s, string t) {
    int m = s.length();
    int n = t.length();

    int dp[m + 1][n + 1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    string ans = "";
    while(i > 0 and j > 0) {
        if(s[i - 1] == t[j - 1]) {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main() {
    string s, t;
    cin >> s >> t;
    cout << findLCS(s, t) << endl;
}