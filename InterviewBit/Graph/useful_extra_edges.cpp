#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &edges, int src, int dest,
          vector<vector<int>> &extraEdges) {
  vector<vector<pair<int, int>>> adj(n + 1);

  for (auto edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];
    adj[u].push_back({v, w});
  }

  int m = n + 1;
  for (auto edge : extraEdges) {
    int u = edge[0];
    int v = edge[1];
    m = max({m, u, v});
  }
  vector<vector<pair<int, int>>> eAdj(m + 1);

  for (auto edge : extraEdges) {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];
    eAdj[u].push_back({v, w});
    eAdj[v].push_back({u, w});
  }
  using pi = pair<pair<int, int>, int>;
  priority_queue<pi, vector<pi>, greater<pi>> pq;

  vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
  dist[src][0] = 0;

  pq.push({{0, 0}, src});  // {{weight, extraEdges used}, node};

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();

    int u = p.second;
    int extraEdgeUsed = p.first.second;
    int d = p.first.first;

    if (u == dest) {
      return d;
    }

    if (d != dist[u][extraEdgeUsed]) continue;

    for (auto child : adj[u]) {
      int v = child.first;
      int w = child.second;

      if (dist[u][extraEdgeUsed] + w < dist[v][extraEdgeUsed]) {
        dist[v][extraEdgeUsed] = dist[u][extraEdgeUsed] + w;
        pq.push({{dist[v][extraEdgeUsed], extraEdgeUsed}, v});
      }
    }
    if (extraEdgeUsed == 0) {
      for (auto child : eAdj[u]) {
        int v = child.first;
        int w = child.second;

        if (dist[u][extraEdgeUsed] + w < dist[v][extraEdgeUsed + 1]) {
          dist[v][extraEdgeUsed + 1] = dist[u][extraEdgeUsed] + w;
          pq.push({{dist[v][extraEdgeUsed + 1], extraEdgeUsed + 1}, v});
        }
      }
    }
  }
  int ans = INT_MAX;

  ans = min({ans, dist[dest][0], dist[dest][1]});
  return ans == INT_MAX ? -1 : ans;
}

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> edges(m, vector<int>(3));
  vector<vector<int>> extraEdges(m, vector<int>(3));

  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  for (int i = 0; i < k; i++) {
    cin >> extraEdges[i][0] >> extraEdges[i][1] >> extraEdges[i][2];
  }

  int src, dest;
  cin >> src >> dest;

  cout << solve(n, edges, src, dest, extraEdges);
}

/*

5 4 1
1 2 2
1 3 2
2 4 1
2 5 4
2 3 3
3 5




6

1 5 5
2
4
6 7 4





*/
