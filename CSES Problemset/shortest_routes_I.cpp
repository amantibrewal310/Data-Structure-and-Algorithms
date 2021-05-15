#include <bits/stdc++.h>
using namespace std;
#define int long long

void dijkstra(vector<vector<pair<int, int>>> &adj, int s, vector<int> &dist, vector<int> &par) {
    int n = adj.size();
    dist.assign(n, LONG_MAX);
    par.assign(n, -1);

    dist[s] = 0;
    using pii = pair<int, int>;  // aliasing
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, s});
    while (!Q.empty()) {
        int v = Q.top().second;
        int weight = Q.top().first;
        Q.pop();

        if (weight != dist[v]) continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                par[to] = v;
                Q.push({dist[to], to});
            }
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    vector<int> dist, par;

    dijkstra(adj, 1, dist, par);

    for (int i = 1; i < n + 1; i++) {
        cout << dist[i] << " ";
    }
}