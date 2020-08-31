//?https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string s) {
    string t = s;
    int n = s.length();
    
    int dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 or j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i - 1] == t[j - 1] and i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << longestRepeatingSubsequence(s) << endl;
        
    }
	
}