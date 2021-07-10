#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for (auto &num : nums) {
    cin >> num;
  }

  int dp[n];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int len = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > len) {
      len = dp[i];
    }
  }
  queue<pair<pair<int, int>, string>> Q;

  for (int i = 0; i < n; i++) {
    if (dp[i] == len) {
      Q.push({{len, i}, to_string(nums[i])});
    }
  }

  vector<string> ans;

  while (!Q.empty()) {
    auto p = Q.front();
    int l = p.first.first;
    int idx = p.first.second;
    string path = p.second;

    Q.pop();
    if (l == 1) {
      ans.push_back(path);
      continue;
    }

    for (int i = idx - 1; i >= 0; i--) {
      if (dp[i] == l - 1 and nums[i] < nums[idx]) {
        Q.push({{l - 1, i}, to_string(nums[i]) + "->" + path});
      }
    }
  }

  for (auto path : ans) {
    cout << path << endl;
  }
}

/*
10
10 22 42 33 21 50 41 60 80 3
*/