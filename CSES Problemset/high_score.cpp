#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e17;
const int NINF = INF * (-1);

int bellmanFord(vector<vector<int>> &edges, int n, int src, int dest) {
    int m = edges.size();
    vector<int> dist(n + 1, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] == INF) continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], NINF);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] == INF) continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + w < dist[v]) {
                dist[v] = NINF;
            }
        }
    }
    return dist[dest] == NINF ? -1 : -dist[dest];
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, -w});
    }

    cout << bellmanFord(edges, n, 1, n) << endl;
}