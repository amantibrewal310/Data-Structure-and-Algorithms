#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(vector<vector<int>> &adj, int node, int par, vector<int> &parent,
         vector<int> &dist) {
  parent[node] = par;
  if (par != -1) dist[node] = dist[par] + 1;

  for (auto child : adj[node]) {
    if (child == par) continue;
    dfs(adj, child, node, parent, dist);
  }
}

int LCA(int u, int v, int h, vector<int> &dist, vector<vector<int>> &up) {
  if (dist[u] < dist[v]) {
    swap(u, v);
  }

  int diff = dist[u] - dist[v];

  int i = 0;

  while (diff > 0) {
    if (diff & 1) {
      u = up[u][i];
    }
    i++;
    diff >>= 1;
  }

  if (u == v) return u;

  for (int i = h - 1; i >= 0; i--) {
    if (up[u][i] == up[v][i]) continue;
    u = up[u][i];
    v = up[v][i];
    // if (u == -1 or v == -1) return -1;
  }
  return up[u][0];
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> parent(n + 1);
  vector<int> dist(n + 1, 0);
  dfs(adj, m, -1, parent, dist);
  // dist[] = -1;

  int h = 0;

  while ((1 << h) <= n) {
    h++;
  }

  vector<vector<int>> up(n + 1, vector<int>(h, -1));

  for (int i = 1; i <= n; i++) {
    up[i][0] = parent[i];
  }

  for (int i = 1; i < h; i++) {
    for (int j = 1; j <= n; j++) {
      int par = up[j][i - 1];
      if (par != -1) up[j][i] = up[par][i - 1];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;

    if (m == LCA(u, v, h, dist, up)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}