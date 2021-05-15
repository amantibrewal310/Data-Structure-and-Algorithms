#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000000 + 7;

int dp[100001];

int dfs(vector<vector<int>> &adj, int src, int dest) {
    if (src == dest) return 1;
    if (dp[src] != -1) return dp[src];
    int ans = 0;

    for (auto v : adj[src]) {
        if (v == src) continue;
        ans = ans % mod;
        ans += dfs(adj, v, dest) % mod;
    }
    return dp[src] = ans % mod;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(adj, 1, n) << endl;
}