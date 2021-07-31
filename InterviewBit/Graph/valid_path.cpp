#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
  if (i >= 0 and i <= n and j >= 0 and j <= m) return true;
  return false;
}

string solve(int x, int y, int n, int r, vector<int> &A, vector<int> &B) {
  int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
  int dy[] = {0, -1, -1, -1, 0, +1, +1, +1};
  set<pair<int, int>> blocked;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      int p = A[i] + dx[j] * r;
      int q = B[i] + dy[j] * r;

      if (isValid(p, q, x, y)) {
        blocked.insert({p, q});
      }
    }
  }
  cout << blocked.size() << endl;

  queue<pair<int, int>> nodes;
  nodes.push({0, 0});
  set<pair<int, int>> vis;
  vis.insert({0, 0});

  while (!nodes.empty()) {
    int p = nodes.front().first;
    int q = nodes.front().second;
    nodes.pop();
    cout << p << " " << q << endl;

    if (p == x and q == y) return "YES";

    for (int i = 0; i < 8; i++) {
      int P = p + dx[i];
      int Q = q + dy[i];

      if (isValid(P, Q, x, y) and vis.find({P, Q}) == vis.end() and
          blocked.find({P, Q}) == blocked.end()) {
        nodes.push({P, Q});
        vis.insert({P, Q});
      }
    }
  }
  return "NO";
}

signed main() {
  int x, y, n, r;
  cin >> x >> y >> n >> r;

  vector<int> A(n), B(n);
  for (int &i : A) {
    cin >> i;
  }
  for (int &i : B) {
    cin >> i;
  }
  cout << solve(x, y, n, r, A, B) << endl;
}

/*
41
67
5
0
17 16 12 0 40
52 61 61 25 31


7
91
8
7
1 7 1 7 1 5 1 6
25 4 74 14 90 58 37 4

*/