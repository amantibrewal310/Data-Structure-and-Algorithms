#include<bits/stdc++.h>
using namespace std;
int n; // Number of vertices
vector<vector<int>> adj; // Adjacency list of graph
vector<int> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visted[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topologicalSort() {
    visited.assign(n, false);
    ans.clear();
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}