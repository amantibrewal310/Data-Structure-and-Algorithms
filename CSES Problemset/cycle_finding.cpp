#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1000000000;
const int NINF = INF * (-1);

void solve(vector<vector<int>> &edges, int n) {
    int m = edges.size();

    vector<int> dist(n + 1);
    vector<int> par(n + 1, -1);
    // dist[1] = 0;
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }
    if (x == -1) {
        cout << "NO" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            x = par[x];
        }
        vector<int> cycle;
        for (int v = x;; v = par[v]) {
            cycle.push_back(v);
            if (v == x and cycle.size() > 1) {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    solve(edges, n);
}