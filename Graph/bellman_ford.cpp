#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // Relax all the edges n - 1 times
    for(int i = 0; i < n - 1; i++) {
        for(auto x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            if(dist[u] != INT_MAX and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Lets check for negative weight cycle
    for(auto x : edges) {
        int u = x[0];
        int v = x[1];
        int w = x[2];
        if(dist[u] != INT_MAX and dist[u] + w < dist[v]) {
            cout << "Negative weight cycle";
            exit(0);
        }
    }
    return dist;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i = 0;i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> dist = bellmanFord(n, 0, edges);
}