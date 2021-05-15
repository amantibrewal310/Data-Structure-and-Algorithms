//?https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src) {
    visited[src] = true;
    for (int nbr : adj[src]) {
        if (!visited[nbr]) {
            dfs(adj, visited, nbr);
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    visited[0] = true;
    vector<int> vertices;
    int connectedComponent = 0;
    for (int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            connectedComponent++;
            vertices.push_back(i);
        }
    }
    cout << connectedComponent - 1 << endl;
    for (int i = 1; i < vertices.size(); i++) {
        cout << vertices[i - 1] << " " << vertices[i] << endl;
    }
}