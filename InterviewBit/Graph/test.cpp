#include <bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B, vector<int> &C) {
  vector<int> indegree(A + 1, 0);

  for (auto node : C) {
    indegree[node]++;
  }

  vector<vector<int>> adj(A + 1);

  for (int i = 0; i < B.size(); i++) {
    adj[B[i]].push_back(C[i]);
  }

  queue<int> Q;
  bool visited[A + 1];
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i < A + 1; i++) {
    if (indegree[i] == 0) {
      Q.push(i);
    }
  }

  set<int> tmp;

  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    tmp.insert(node);

    // for(auto child : )
    for (auto child : adj[node]) {
      indegree[child]--;
      if (indegree[child] == 0) {
        Q.push(child);
      }
    }
  }
  // cout << tmp.size() << endl;
  //   for (auto x : tmp) {
  //     cout << x << " ";
  //   }

  return tmp.size() == A;
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);

  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  cout << solve(n, a, b) << endl;
}
/*
8 6
1 2 3 4 5 8
2 3 4 5 6 7


*/