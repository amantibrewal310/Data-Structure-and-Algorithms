//?https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> dp;
bool isValid(int i, int j, int n, int m) {
    if(i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}
int solve(vector<vector<int>> &mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();

    if(i == n - 1 and j == m - 1) {
        return mat[i][j];
    }
    
    if(!isValid(i, j, n, m))
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int op1 = mat[i][j] + solve(mat, i, j + 1);
    int op2 = mat[i][j] + solve(mat, i + 1, j);

    return dp[i][j] = min(op1, op2);
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    dp.assign(n, vector<int>(m, -1));
    cout << solve(grid, 0, 0) << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}