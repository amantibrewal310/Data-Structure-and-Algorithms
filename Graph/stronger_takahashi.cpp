//?https://atcoder.jp/contests/abc213/tasks/abc213_e

#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
  if (i >= 0 and i < n and j >= 0 and j < m) return true;
  return false;
}

signed main() {
  int n, m;
  cin >> n >> m;

  vector<string> mat(n);

  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[0][0] = 0;

  deque<vector<int>> Q;
  Q.push_back({0, 0, 0});

  while (!Q.empty()) {
    vector<int> v = Q.front();
    Q.pop_front();

    int x = v[1];
    int y = v[2];
    int d = v[0];

    int dx[] = {+1, -1, 0, 0};
    int dy[] = {0, 0, +1, -1};

    for (int k = 0; k < 4; k++) {
      int X = x + dx[k];
      int Y = y + dy[k];

      if (!isValid(X, Y, n, m)) continue;
      if (mat[X][Y] == '.' and dist[x][y] < dist[X][Y]) {
        dist[X][Y] = dist[x][y];
        Q.push_front({dist[X][Y], X, Y});
      }

      if (mat[X][Y] == '#') {
        for (int i = X - 1; i < X + 2; i++) {
          for (int j = Y - 1; j < Y + 2; j++) {
            if (!isValid(i, j, n, m)) continue;

            if (dist[x][y] + 1 < dist[i][j]) {
              dist[i][j] = dist[x][y] + 1;
              Q.push_back({dist[i][j], i, j});
            }
          }
        }
      }
    }
  }
  cout << dist[n - 1][m - 1] << endl;
}