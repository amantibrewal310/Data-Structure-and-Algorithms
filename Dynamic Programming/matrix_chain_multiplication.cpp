//?https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int solve(vector<int> &dimensions, int i, int j) {
    if(i >= j)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = INT_MAX;
    
    for(int k = i; k < j; k++) {
        int temp = solve(dimensions, i, k) + solve(dimensions, k + 1, j) + dimensions[i - 1] * dimensions[k] * dimensions[j];
        ans = min(ans, temp);
    }
    
    return dp[i][j] = ans;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> dimensions(n);
        for(int &dimension : dimensions)
            cin >> dimension;
        memset(dp, -1, sizeof(dp));
        
        cout << solve(dimensions, 1, n - 1) << endl;
        
    }
    
	
}