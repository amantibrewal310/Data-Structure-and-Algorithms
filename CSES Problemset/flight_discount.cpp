#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dijkstra(vector<pair<int, int>> adj[], int src, int n) {
    vector<int> dist(n, LONG_MAX);
    dist[src] = 0;
    using pii = pair<int, int>;  // aliasing
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Q.push({0, src});

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        int u = p.second;
        int w = p.first;

        if (w != dist[u]) continue;

        for (auto nbr : adj[u]) {
            int v = nbr.first;
            int wt = nbr.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                Q.push({dist[v], v});
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    return dist;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj1[n + 1];
    vector<pair<int, int>> adj2[n + 1];
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    vector<int> distFromSrc = dijkstra(adj1, 1, n + 1);
    vector<int> distFromDest = dijkstra(adj2, n, n + 1);

    int ans = LONG_MAX;

    for (auto edge : edges) {
        // cout << edge.size() << endl;
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int cost = distFromSrc[u] + distFromDest[v] + w / 2;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}