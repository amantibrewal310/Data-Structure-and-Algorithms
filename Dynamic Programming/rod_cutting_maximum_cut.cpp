//?https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include<bits/stdc++.h>
using namespace std;

int dp[3][4005];

int maxCut(vector<int> &length, int i, int totalLen) {
    if(totalLen == 0)
        return 0;
    if(i >= length.size()) {
        if(totalLen == 0)
            return 0;
        else 
            return -2;
    }
    if(dp[i][totalLen] != -1)
        return dp[i][totalLen];
    
    if(length[i] <= totalLen) {
        int op1 = maxCut(length, i, totalLen - length[i]);
        int op2 = maxCut(length, i + 1, totalLen);

        if(op1 == -2) {
            dp[i][totalLen] = op2;
        } else {
            dp[i][totalLen] = max(op1 + 1, op2);
        }
    } else {
        dp[i][totalLen] = maxCut(length, i + 1, totalLen);
    }
    return dp[i][totalLen];
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> length(3);
        for(auto &len : length)
            cin >> len;
        memset(dp, -1, sizeof(dp));
        cout << maxCut(length, 0, n) << endl;
        
    }
}