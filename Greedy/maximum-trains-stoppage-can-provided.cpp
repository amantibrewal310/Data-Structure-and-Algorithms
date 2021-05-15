//?https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

signed main() {
  // n - no of platform
  // m - no of trains
  int n, m;
  cin >> n >> m;

  vector<vector<int>> input(m);

  for (int i = 0; i < m; i++) {
    int arrTime, depTime, platformNo;
    cin >> arrTime >> depTime >> platformNo;
    input[i] = {arrTime, depTime, platformNo};
  }

  vector<vector<pair<int, int>>> tmp(n);

  for (int i = 0; i < m; i++) {
    int arrTime = input[i][0];
    int depTime = input[i][1];
    int platformNo = input[i][2];

    tmp[platformNo - 1].push_back({arrTime, depTime});
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    sort(tmp[i].begin(), tmp[i].end(), cmp);
    int prev = tmp[i][0].second;
    // cout << tmp[i].size() << endl;
    cnt++;

    for (int j = 1; j < tmp[i].size(); j++) {
      // cout << tmp[i][j].first << " " << tmp[i][j].second << endl;
      if (tmp[i][j].first > prev) {
        // cout << i << endl;
        cnt++;
        prev = max(prev, tmp[i][j].second);
      }
    }
    // cout << "---------" << endl;
  }
  cout << cnt << endl;
}

/*
3 6
1000 1030 1
1010 1030 1
1000 1020 2
1030 1230 2
1200 1230 3
0900 1005 1

*/
