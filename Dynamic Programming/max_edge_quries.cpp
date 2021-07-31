#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &adj,
         vector<vector<pair<int, int>>> &dp, vector<int> &dist, int node,
         int par, int weight) {
  dp[node][0] = {par, weight};
  dist[node] = dist[par] + 1;

  for (auto child : adj[node]) {
    if (child.first == par) continue;
    dfs(adj, dp, dist, child.first, node, child.second);
  }
}

int processQuery(vector<vector<pair<int, int>>> &adj,
                 vector<vector<pair<int, int>>> &dp, vector<int> &dist, int u,
                 int v) {
  int ans = 0;

  if (dist[u] < dist[v]) swap(u, v);

  int diff = dist[u] - dist[v];

  while (diff) {
    int jump = (int)log2(diff);
    ans = max(ans, dp[u][jump].second);
    u = dp[u][jump].first;
    diff -= (1 << jump);
  }

  if (u == v) return ans;
  int h = dp[0].size();
  for (int i = h - 1; i >= 0; i--) {
    if (dp[u][i].first != dp[v][i].first) {
      ans = max(ans, dp[u][i].second);
      ans = max(ans, dp[v][i].second);

      u = dp[u][i].first;
      v = dp[v][i].first;
    }
  }
  ans = max(ans, dp[u][0].second);
  ans = max(ans, dp[v][0].second);
  return ans;
}

signed main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int h = 0;

  while ((1 << h) <= n) {
    h++;
  }
  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(h));
  vector<int> dist(n + 1);
  dist[0] = -1;

  dfs(adj, dp, dist, 1, 0, 0);

  for (int i = 1; i < h; i++) {
    for (int node = 1; node <= n; node++) {
      int par = dp[node][i - 1].first;
      int w = dp[node][i - 1].second;

      dp[node][i] = {dp[par][i - 1].first, max(w, dp[par][i - 1].second)};
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    cout << processQuery(adj, dp, dist, u, v) << endl;
  }
}

/*
13 12
10 6 42
3 2 18468
12 7 6335
9 5 26501
2 1 19170
8 3 15725
7 1 11479
4 2 29359
6 3 26963
11 4 24465
5 3 5706
13 11 28146




*/