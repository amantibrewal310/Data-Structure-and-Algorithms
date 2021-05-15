#include <bits/stdc++.h>
using namespace std;
const int mod = 10e9 + 7;

int dfs(vector<vector<int>> &adj, int src, int dest) {
    if (src == dest) return 1;

    int ans = 0;

    for (auto v : adj[src]) {
        ans += dfs(adj, v, dest);
    }
    return ans;
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
    cout << dfs(adj, 1, n) << endl;
}