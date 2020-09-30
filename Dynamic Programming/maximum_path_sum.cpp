//?https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
#include<bits/stdc++.h>
using namespace std;
#define ll int long long
vector<vector<ll>> dp;
    
bool isValid(int i, int j, int n, int m) {
    if(i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}

ll solve(vector<vector<int>> &mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();
    
    if(i == n - 1 and j >= 0 and j < m) {
        return (ll)mat[i][j];
    }
    
    if(!isValid(i, j, n, m)) {
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll op1 = (ll)mat[i][j] + solve(mat, i + 1, j);
    ll op2 = (ll)mat[i][j] + solve(mat, i + 1, j - 1);
    ll op3 = (ll)mat[i][j] + solve(mat, i + 1, j + 1);
    
    return dp[i][j] = max({op1, op2, op3});
}
    
int maximumPath(int N, vector<vector<int>> Matrix)
{
    // code here
    int n = Matrix.size();
    int m = Matrix[0].size();
    
    dp.assign(n, vector<ll>(m, -1));
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp = solve(Matrix, 0, i);
        
        ans = max(ans, tmp);
    }
    dp.clear();
    return ans;
    
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << maximumPath(n, mat) << endl;
}