//?https://www.codingninjas.com/codestudio/problems/travelling-salesman-problem_1385180
#include <bits/stdc++.h>
using namespace std;

int dp[17][1 << 16];

int solve(vector<vector<int>> &dist, int node, int mask, int n) {
  if (mask == (1 << n) - 1) {
    return dist[node][0];
  }
  if (dp[node][mask] != -1) return dp[node][mask];

  int ans = INT_MAX;

  // Try to goto an unvisited city
  for (int city = 0; city < n; city++) {
    if ((mask & (1 << city)) == 0) {
      int temp = dist[node][city] + solve(dist, city, mask | (1 << city), n);
      ans = min(ans, temp);
    }
  }
  return dp[node][mask] = ans;
}

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> dist(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dist[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(dist, 0, 1, n) << endl;
}

/*
4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0

3
0 3 2
3 0 1
2 1 0



85
6

*/