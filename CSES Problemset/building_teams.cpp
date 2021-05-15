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
    vector<int> visited(n + 1, 0);
    queue<int> Q;

    bool flag = true;
    for (int i = 1; i < n + 1; i++) {
        if (visited[i] == 0) {
            Q.push(i);
            visited[i] = 1;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = visited[u] == 1 ? 2 : 1;
                        Q.push(v);
                    } else if (visited[v] == visited[u]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        for (int i = 1; i < n + 1; i++) {
            cout << visited[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}