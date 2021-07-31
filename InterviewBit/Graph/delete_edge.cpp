#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &weights, vector<int> &visited,
        int node, vector<long long> &subStreeSum) {
  visited[node] = 1;
  int sum = weights[node - 1];

  for (auto child : adj[node]) {
    if (visited[child] == 0) {
      sum += dfs(adj, weights, visited, child, subStreeSum);
    }
  }
  return subStreeSum[node] = sum;
}

int deleteEdge(vector<int> &A, vector<vector<int>> &B) {
  int n = A.size();
  vector<vector<int>> adj(n + 1);

  for (auto edge : B) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int res = INT_MIN;
  const int mod = 1e9 + 7;
  vector<long long> subTreeSum(n + 1, 0);
  vector<int> visited(n + 1, 0);
  dfs(adj, A, visited, 1, subTreeSum);

  for (auto x : subTreeSum) {
    cout << x << " ";
  }
  cout << endl;

  for (auto edge : B) {
    int u = edge[0];
    int v = edge[1];
    long long sum1 = min(subTreeSum[u], subTreeSum[v]);
    long long sum2 = subTreeSum[1] - sum1;

    long long prod = ((sum1 % mod) * (sum2 % mod)) % mod;
    res = max((long long)res, prod);
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  vector<int> weights(n);
  for (int &w : weights) {
    cin >> w;
  }
  int m;
  cin >> m;
  vector<vector<int>> edges(m, vector<int>(2));

  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  cout << deleteEdge(weights, edges) << endl;
}

/*

4
10 5 12 6
3
1 2
1 4
4 3

*/