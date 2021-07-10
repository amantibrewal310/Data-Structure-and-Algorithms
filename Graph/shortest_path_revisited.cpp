//?https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/

#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  pq.push({0, 1, 0});
  vector<vector<int>> dis(n + 1, vector<int>(k + 1, INT_MAX));
  pq.push({1, 1, 0});
  dis[1][0] = 0;
  while (!pq.empty()) {
    auto v = pq.top();
    pq.pop();
    int u = v[1];
    // int w = v[0];
    int coupons = v[2];

    for (auto nbr : adj[u]) {
      int w = nbr.second;
      int v = nbr.first;
      if (dis[u][coupons] + w < dis[v][coupons]) {
        dis[v][coupons] = dis[u][coupons] + w;
        pq.push({dis[v][coupons], v, coupons});
      }
      if (coupons + 1 <= k) {
        if (dis[u][coupons] < dis[v][coupons + 1]) {
          dis[v][coupons + 1] = dis[u][coupons];
          pq.push({dis[v][coupons + 1], v, coupons + 1});
        }
      }
    }
  }
  vector<int> ans;

  for (int i = 1; i <= n; i++) {
    int mn = dis[i][0];
    for (int j = 0; j <= k; j++) {
      mn = min(mn, dis[i][j]);
    }
    ans.push_back(mn);
  }
  for (auto x : ans) {
    cout << x << " ";
  }
}