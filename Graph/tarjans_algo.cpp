//?https://leetcode.com/problems/critical-connections-in-a-network/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &adj, vector<int> &visited, int src,
                   int discoveredId, int lowId) {
  visited[src] = true;

  for (int nbr : adj[src]) {
    if (nbr == src) continue;

    if (!visited[nbr]) {
      pair<int, int> p = dfs(adj, visited, nbr, discoveredId + 1, lowId + 1);

      if (p.second > lowId) {
      }
    }
  }
}

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> edges(n);

  for (auto &edge : edges) {
    cin >> edge[0] >> edge[1];
  }
}