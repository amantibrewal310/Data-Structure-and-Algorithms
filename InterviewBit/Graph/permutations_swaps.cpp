#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node,
         vector<int> &nodes) {
  visited[node] = true;

  nodes.push_back(node);

  for (auto child : adj[node]) {
    if (!visited[child]) {
      dfs(adj, visited, child, nodes);
    }
  }
}

int solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C) {
  int n = A.size();

  vector<vector<int>> adj(n + 1);
  vector<bool> visited(n + 1, 0);

  for (auto edge : C) {
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vector<int>> components;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      vector<int> temp;
      dfs(adj, visited, i, temp);
      components.push_back(temp);
    }
  }
  vector<set<int>> t;

  for (auto component : components) {
    vector<int> a, b;

    for (auto pos : component) {
      a.push_back(A[pos - 1]);
      b.push_back(B[pos - 1]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int j = 0; j < a.size(); j++) {
      if (a[j] != b[j]) return 0;
    }
  }

  return 1;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> A(n);
    vector<int> B(n);

    for (auto &x : A) {
      cin >> x;
    }
    for (auto &x : B) {
      cin >> x;
    }

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
      cin >> edges[i][0] >> edges[i][1];
    }
    int ans = solve(A, B, edges);
    if (ans) {
      cout << "YES" << endl;

    } else {
      cout << "NO" << endl;
    }
  }
}
