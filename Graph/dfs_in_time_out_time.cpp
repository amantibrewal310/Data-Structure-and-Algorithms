#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list
int n; // Number of vertices.
int m; // Number of Edges.

vector<int> color; // Color = 0 for not visited, 1 for visited, 2 for exited.

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for(int u : adj[v]) {
        if(color[u] == 0)
            dfs(u);
    }
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

signed main() {

    cin>>n>>m;
    
    int x,y;

    while(m--) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}