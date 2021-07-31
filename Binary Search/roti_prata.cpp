//?https://www.spoj.com/problems/PRATA/
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &rank, int k, int time) {
  int n = rank.size();
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int temp = 0;
    int j = 1;
    while (temp + j * rank[i] <= time) {
      cnt++;
      temp += j * rank[i];
      j++;
    }
  }
  return cnt >= k;
}

void solve() {
  int p, n;
  cin >> p >> n;
  vector<int> ranks(n);

  for (int i = 0; i < n; i++) {
    cin >> ranks[i];
  }
  sort(ranks.begin(), ranks.end());
  int low = 0;
  int high = 0;

  for (int i = 1; i <= p; i++) {
    high += (i * ranks[0]);
  }

  int ans = high;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(ranks, p, mid)) {
      // cout << mid << endl;
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}