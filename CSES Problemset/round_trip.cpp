#include <bits/stdc++.h>
using namespace std;
int cycleEnd = -1;
int cycleStart = -1;

bool dfs(vector<int> adj[], vector<int> &visited, vector<int> &parent, int u, int par) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (v == par)
            continue;
        else if (visited[v] == 0) {
            parent[v] = u;
            if (dfs(adj, visited, parent, v, parent[v])) {
                return true;
            }
        } else if (visited[v] == 1) {
            cycleEnd = u;
            cycleStart = v;
            return true;
        }
    }
    visited[u] = 2;
    return false;
}

void findCycle(vector<int> adj[], int n) {
    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i < n + 1; i++) {
        if (visited[i] == 0 and dfs(adj, visited, parent, i, parent[i])) {
            break;
        }
    }
    if (cycleStart == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int i = cycleEnd; i != cycleStart; i = parent[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(cycleStart);
        // reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int i = 0; i < (int)cycle.size(); i++) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
}

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
    findCycle(adj, n);
}