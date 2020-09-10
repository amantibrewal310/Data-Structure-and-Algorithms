//?https://www.spoj.com/problems/PT07Z/
#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
int maxD, maxNode;

void dfs(vector<int> adj[],int u, int d) {
    visited[u] = true;
    if(d > maxD) {
        maxD = d;
        maxNode = u;
    }
    for(int child : adj[u]) {
        if(visited[child] == 0) {
            dfs(adj, child, d + 1);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n + 1, 0);
    maxD = -1;
    dfs(adj, 1, 0);
    maxD = -1;
    visited.clear();
    visited.assign(n + 1, 0);
    dfs(adj, maxNode, 0);
    cout << maxD << endl;
    
}