//?https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
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
    int t;
    cin >> t;
    int cnt = 1;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n + 1, 0);
        color.resize(n + 1);
        bool flag = 1;
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0) {
                if(!dfs(adj, i, 0)) {
                    // cout << i << endl;
                    flag = 0;
                    break;
                }
            }
        }
        cout << "Scenario #" << cnt << ":" << endl;
        if(flag) {
            cout << "No suspicious bugs found!" << endl;
        } else {
            cout << "Suspicious bugs found!" << endl;
        }
        cnt++;
        visited.clear();
        color.clear();
    }
}