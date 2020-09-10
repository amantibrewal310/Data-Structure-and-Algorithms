#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> all_pair_shortest_path(int n, vector< vector<pair<int, int>> > &adj) {
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, 2e9));

    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;

        for(pair<int, int> ed : adj[i]) {
            int nb = ed.first;
            int w = ed.second;
            dist[i][nb] = w;
        }
    }

    for(int k = 1; k <= n; k++) {
        // kth phase

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}