//?https://atcoder.jp/contests/abc184/tasks/abc184_f
// This problem is based on the meet in the middle algo

#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> &times, int maxTime) {
  int n = times.size();

  set<int> left, right;
  for (int i = 0; i <= n / 2; i++) {
    // cout << times[i] << endl;
    vector<int> temp;
    for (auto ele : left) {
      temp.push_back(ele + times[i]);
    }
    left.insert(times[i]);

    for (auto ele : temp) {
      left.insert(ele);
    }
  }
  // cout << left.size() << endl;

  for (int i = (n / 2) + 1; i < n; i++) {
    vector<int> temp;
    for (auto ele : right) {
      temp.push_back(ele + times[i]);
    }
    right.insert(times[i]);
    for (auto ele : temp) {
      right.insert(ele);
    }
  }
  right.insert(0);
  left.insert(0);

  int ans = 0;

  for (auto ele : left) {
    if (ele > maxTime) break;
    int key = maxTime - ele;
    // cout << key << endl;
    auto it = right.upper_bound(key);
    if (it != right.begin()) {
      it--;
    }
    ans = max(ans, ele + *it);
  }
  return ans;
}

signed main() {
  int n, T;
  cin >> n >> T;
  vector<int> times(n);

  for (auto &time : times) {
    cin >> time;
  }
  cout << solve(times, T) << endl;
}