#include <bits/stdc++.h>
using namespace std;

int longestSubsequenceLength(const vector<int> &A) {
  int n = A.size();
  if (n == 0) return 0;
  int dp[n];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (A[i] > A[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int t[n];
  memset(t, 0, sizeof(t));

  for (int i = n - 1; i >= 0; i--) {
    t[i] = 1;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[i]) {
        t[i] = max(t[i], t[j] + 1);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (A[i] == A[j]) continue;
      ans = max(ans, dp[i] + t[j]);
    }
  }
  return ans;
}

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << longestSubsequenceLength(nums) << endl;
}