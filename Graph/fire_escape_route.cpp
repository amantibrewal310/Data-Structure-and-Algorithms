//?https://www.codechef.com/problems/FIRESC
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
vector<bool> visited;

int dfs(vector<int> adj[], int u) {
    visited[u] = 1;
    int cnt = 1;
    for(int child : adj[u]) {
        if(visited[child] == 0) {
            cnt += dfs(adj, child);
        }
    }
    return cnt;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0, ways = 1;
        visited.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(visited[i] == false) {
                int ccSize = dfs(adj, i);
                cnt++;

                ways = (ways * ccSize) % mod;
            }
        
        }
        ways %= mod;
        cout << cnt << " " << ways << endl;
        visited.clear();
    }
}