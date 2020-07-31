#include<bits/stdc++.h>
using namespace std;

/*
    Count no. of BST's that can be formed using N nodes numbered from 1, 2, 3 ...... n

    Catalan Number - 2nCn / (n + 1)

    Similar Problem - Binary Trees - n! * Catalan No.
                      Unlabelled Binary Trees - BST - Catalan No.
*/

int catalanNumber(int n) {
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for(int i = 2; i < n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

signed main() {
    int n;
    cin >> n;
    cout << catalanNumber(n) << endl;
}

