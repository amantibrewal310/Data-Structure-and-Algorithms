#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
vector <bool> visited(1000, false);


void dfs(int v) {
    visited[v] = true;

    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

signed main() {

    int nodes, edges, x, y;
    cin >> nodes >> edges;
    
    for(int i = 0; i < edges; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cc_cnt = 0;
    for(int i=1; i<=nodes; i++) {
        if(!visited[i]) {
            dfs(i);
            cc_cnt++;
        }
    }
    cout << cc_cnt << endl;
}