#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
  if (i >= 0 and i < n and j >= 0 and j < m) return true;
  return false;
}

int solve(int A, int B, vector<string> &C) {
  vector<vector<int>> visited(A, vector<int>(B, 0));
  map<pair<int, int>, vector<pair<pair<int, int>, int>>> adj;

  int dx[] = {+1, -1, 0, 0};
  int dy[] = {0, 0, +1, -1};

  string dir = "DURL";

  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (!isValid(x, y, A, B)) continue;
        if (C[i][j] == dir[k]) {
          adj[{i, j}].push_back({{x, y}, 0});
        } else {
          adj[{i, j}].push_back({{x, y}, 1});
        }
      }
    }
  }

  deque<pair<pair<int, int>, int>> Q;
  Q.push_back({{0, 0}, 0});
  visited[0][0] = 1;

  vector<vector<int>> dist(A, vector<int>(B, INT_MAX));
  dist[0][0] = 0;

  for (auto node : adj) {
    cout << node.first.first << " " << node.first.second << ": ";
    for (auto child : node.second) {
      cout << child.first.first << " " << child.first.second << " "
           << child.second << endl;
    }
    cout << "----" << endl;
  }

  // while (!Q.empty()) {
  //   auto p = Q.front();
  //   Q.pop_front();

  //   int x = p.first.first;
  //   int y = p.first.second;
  //   int d = p.second;

  //   for (auto child : adj[{x, y}]) {
  //     int X = child.first.first;
  //     int Y = child.first.second;

  //     int w = child.second;

  //     if (dist[x][y] + w < dist[X][Y]) {
  //       dist[X][Y] = dist[x][y] + w;

  //       if (dist[X][Y] == d) {
  //         Q.push_front({{X, Y}, dist[X][Y]});
  //       } else {
  //         Q.push_back({{X, Y}, dist[X][Y]});
  //       }
  //     }
  //   }
  // }

  return dist[A - 1][B - 1];
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);

  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  cout << solve(n, m, mat) << endl;
}
/*
1
10
RRRRRRRRRR

3
3
RRR
DDD
UUU


*/