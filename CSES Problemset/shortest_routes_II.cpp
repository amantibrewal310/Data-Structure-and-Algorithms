#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, LONG_MAX));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[u][v], w);
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;

    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dis[i][k] < LONG_MAX and dis[k][j] < LONG_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        // cout << dis[u][v] != LONG_MAX ? dis[u][v] : -1 << endl;
        if (dis[u][v] == LONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << dis[u][v] << endl;
        }
    }
}