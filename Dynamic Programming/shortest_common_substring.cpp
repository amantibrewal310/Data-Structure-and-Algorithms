//?https://leetcode.com/problems/find-the-shortest-superstring/
#include <bits/stdc++.h>
using namespace std;

int dp[18][1 << 18];
int parent[18][1 << 18];

int findExtraChar(string &s, string &t) {
  int n = s.length();
  int m = t.length();

  int ans = n + m;

  for (int len = 1; len <= min(m, n); len++) {
    int i = n - len;
    int j = 0;

    bool isMatch = true;
    while (i < n and j < m) {
      if (s[i] != t[j]) {
        isMatch = false;
        break;
      }
      i++;
      j++;
    }
    if (isMatch) {
      ans = min(ans, n + m - len);
    }
  }
  return ans - n;
}

int solve(vector<string> &words, int i, int mask) {
  int n = words.size();
  if (mask == (1 << n) - 1) {
    return 0;
  }
  if (dp[i][mask] != -1) return dp[i][mask];

  int ans = INT_MAX;

  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j))) {
      int x = findExtraChar(words[i], words[j]);
      int temp = x + solve(words, j, mask | (1 << j));
      if (temp < ans) {
        parent[i][mask] = j;
      }
      ans = min(ans, temp);
    }
  }
  return dp[i][mask] = ans;
}

signed main() {
  int n;
  cin >> n;
  vector<string> words(n);

  for (auto &word : words) {
    cin >> word;
  }
  memset(dp, -1, sizeof(dp));
  memset(parent, -1, sizeof(parent));
  int ans = INT_MAX;
  int start = -1;
  for (int i = 0; i < n; i++) {
    int temp = words[i].length() + solve(words, i, (1 << i));
    if (temp < ans) {
      start = i;
    }
    ans = min(ans, temp);
  }
  vector<int> path;
  int mask = (1 << start);
  // cout << start << endl;
  cout << "par: " << parent[start][mask] << endl;
  cout << mask << endl;

  while (parent[start][mask] != -1) {
    path.push_back(start);
    start = parent[start][mask];
    mask |= (1 << start);
    // cout << mask << endl;
    // cout << start << endl;
  }
  path.push_back(start);

  for (auto x : path) {
    cout << x << " ";
  }
  cout << endl;

  cout << ans << endl;
}

/*
5
catg ctaagt gcta ttca atgcatc
*/