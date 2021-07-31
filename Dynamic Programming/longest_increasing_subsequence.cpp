#include <bits/stdc++.h>
using namespace std;

/*
    ?LONGEST INCREASING SUBSEQUENCE
    Types of solution

    1. DP - 1 (Standard)
    2. DP - 2 (Tricky)
    3. DP - 2 with binary search
    4. DP using segment tree

*/

int solveDP1(vector<int> nums) {
  int n = nums.size();
  int dp[n] = {0};

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
  }
  return ans;
}

int solveDP2(vector<int> nums) {
  int n = nums.size();
  int dp[n + 1];
  dp[0] = INT_MIN;
  for (int i = 1; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  for (int i = 0; i < n; i++) {
    for (int length = 0; length < n; length++) {
      if (dp[length] < nums[i] and nums[i] < dp[length + 1]) {
        dp[length + 1] = nums[i];
      }
    }
  }
  int lis = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i] != INT_MAX) lis = i;
  }
  return lis;
}
// with binary search
int solveDP3(vector<int> nums) {
  int n = nums.size();
  int dp[n + 1];
  dp[0] = INT_MIN;
  for (int i = 1; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  for (int i = 0; i < n; i++) {
    int length = upper_bound(dp, dp + n + 1, nums[i]) - dp;

    if (dp[length - 1] < nums[i] and nums[i] < dp[length]) dp[length] = nums[i];
  }
  int lis = 0;
  for (int i = 1; i <= n; i++) {
    // cout << dp[i] << " ";
    if (dp[i] != INT_MAX) lis = i;
  }
  return lis;
}

//

int binarySearch(vector<int> &nums, vector<int> &lis, int low, int high,
                 int key) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[lis[mid]] >= key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int solveDP4(vector<int> &nums) {
  int n = nums.size();

  int parent[n];
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  vector<int> lis(n + 1);
  int length = 0;

  for (int i = 0; i < n; i++) {
    int j = binarySearch(nums, lis, 1, length, nums[i]);
    parent[i] = lis[j - 1];
    lis[j] = i;
    if (j > length) {
      length = j;
    }
  }
  return length;
}

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &num : nums) cin >> num;

  cout << solveDP4(nums) << endl;
}