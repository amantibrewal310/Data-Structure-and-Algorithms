#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005];

int solve(vector<vector<int>> &v, int i) {
    int n = v.size();
    if (i >= n) return 0;

    if (dp[i] != -1) return dp[i];

    int a = v[i][0];
    int b = v[i][1];

    vector<int> val = {b + 1, b + 1, 0};
    auto lower = lower_bound(v.begin(), v.end(), val);
    int idx = lower - v.begin();

    int op1 = v[i][2] + solve(v, idx);
    int op2 = solve(v, i + 1);

    return dp[i] = max(op1, op2);
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    cout << solve(v, 0) << endl;
}