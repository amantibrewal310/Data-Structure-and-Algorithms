#include <bits/stdc++.h>
using namespace std;

vector<int> topSort(vector<vector<int>> &adj, int n) {
  vector<int> indegree(n, 0);

  for (int i = 0; i < n; i++) {
    for (auto child : adj[i]) {
      indegree[child]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      Q.push(i);
    }
  }
  vector<int> ans;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    ans.push_back(node);

    for (auto child : adj[node]) {
      indegree[child]--;
      if (indegree[child] == 0) {
        Q.push(child);
      }
    }
  }
  return ans;
}

int solve(vector<int> &A) {
  int n = A.size();
  vector<vector<int>> adj(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    if (A[i] == -1) {
      root = i;
      continue;
    };
    adj[A[i]].push_back(i);
  }

  vector<int> topoOrder = topSort(adj, n);

  for (int i = 0; i < n; i++) {
    cout << topoOrder[i] << " ";
  }
  cout << endl;

  vector<int> dist(n, INT_MAX);
  dist[topoOrder[0]] = 0;
  for (int i = 0; i < topoOrder.size(); i++) {
    int node = topoOrder[i];

    for (auto child : adj[node]) {
      if (dist[node] - 1 < dist[child]) {
        dist[child] = dist[node] - 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;

  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    ans = max(ans, -dist[i]);
  }
  return ans;
}

signed main() {
  int n;
  cin >> n;
  vector<int> par(n);

  for (int &x : par) {
    cin >> x;
  }
  cout << solve(par) << endl;
}

/*
5
-1 0 0 0 3

*/
