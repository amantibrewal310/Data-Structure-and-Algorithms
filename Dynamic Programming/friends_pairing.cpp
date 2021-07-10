#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

void solve(int n, int i, vector<string> &curr) {
  if (i > n) {
    ans.push_back(curr);
    return;
  }
  curr.push_back(to_string(i));
  solve(n, i + 1, curr);
  curr.pop_back();

  for (int j = i + 1; j <= n; j++) {
    string t = to_string(i) + to_string(j);
    curr.push_back(t);
    solve(n, j + 1, curr);
    curr.pop_back();
  }
}

signed main() {
  int n;
  // cin >> n;
  n = 3;
  vector<string> curr;
  solve(n, 1, curr);
  for (auto x : ans) {
    for (auto s : x) {
      cout << s << " ";
    }
    cout << endl;
  }
}