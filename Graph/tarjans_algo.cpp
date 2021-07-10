//?https://leetcode.com/problems/critical-connections-in-a-network/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> adj, bridges;
  vector<int> parent, visited, low;
  int timer = 0;

  void dfs(int node) {
    visited[node] = low[node] = timer++;

    for (int child : adj[node]) {
      if (visited[child] == -1) {
        parent[child] = node;
        dfs(child);

        low[node] = min(low[node], low[child]);

        if (low[child] > visited[node]) {
          bridges.push_back({node, child});
        }

      } else if (child != parent[node]) {
        low[node] = min(low[node], visited[child]);
      }
    }
  }
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    adj.resize(n);
    parent.resize(n, -1);
    visited.resize(n, -1);
    low.resize(n, -1);
    timer = 0;

    for (int i = 0; i < (int)connections.size(); i++) {
      int u = connections[i][0];
      int v = connections[i][1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      if (visited[i] == -1) {
        dfs(i);
      }
    }
    return bridges;
  }
};
