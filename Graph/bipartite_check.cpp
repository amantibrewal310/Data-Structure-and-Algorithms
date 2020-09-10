#include<bits/stdc++.h>
using namespace std;
vector<int> visited;
vector<int> color;
bool dfs(vector<int> adj[], int u, int c) {
    visited[u] = 1;
    color[u] = c;

    for(int child : adj[u]) {
        if(visited[child] == 0) {
            if(dfs(adj, child, c ^ 1) == false) {
                return false;
            }
        } else if(color[child] == color[u]) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n, 0);
    color.resize(n);

    if(dfs(adj, 0, 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}