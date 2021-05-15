//?https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
    }
    visited[0] = true;
    queue<int> Q;
    Q.push(1);

    visited[1] = true;
    bool flag = false;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == n) {
            flag = true;
            break;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
    if (flag) {
        vector<int> path;
        int u = n;
        while (u != 1) {
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(1);
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (auto v : path) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}