#include <bits/stdc++.h>
using namespace std;

int solve(string wall, int k) {
  int n = wall.size();

  map<char, vector<int>> occur;

  for (int i = 0; i < n; i++) {
    if (occur.find(wall[i]) == occur.end()) {
      occur[wall[i]] = {i, i};
    } else {
      occur[wall[i]][1] = i;
    }
  }
  int ans = 0;
  for (auto p : occur) {
    vector<int> v = p.second;
    int cnt = 0;

    for (int i = v[0]; i <= v[1]; i++) {
      if (wall[i] != p.first) {
        cnt++;
      }
    }
    if (cnt <= k) {
      int len = v[1] - v[0] + 1;
      ans = max(ans, len);
    }
  }
  return ans;
}

signed main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  cout << solve(s, k) << endl;
}