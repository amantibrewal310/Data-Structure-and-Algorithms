#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001][2];

const int mod = 1e9 + 7;

int solve(vector<int> &nums, int i, int prev, bool flag) {
  int n = nums.size();
  if (i >= n) return flag;

  if (prev != -1 and dp[i][prev][flag] != -1) return dp[i][prev][flag];

  if (prev == -1) {
    int op1 = solve(nums, i + 1, i, 0);
    int op2 = solve(nums, i + 1, prev, flag);

    int ans = (op1 + op2) % mod;
    return ans;
  }
  int ans = 0;
  int diff = abs(nums[i] - nums[prev]);

  if (diff <= 1) {
    int temp = solve(nums, i + 1, i, 1);
    ans = (ans + temp) % mod;
  } else {
    int temp = solve(nums, i + 1, i, flag);
    ans = (ans + temp) % mod;
  }

  int temp = solve(nums, i + 1, prev, flag);
  ans = ans + temp % mod;

  return dp[i][prev][flag] = ans;
}

int magicalSubsequence(vector<int> &nums) {
  int n = nums.size();

  memset(dp, -1, sizeof(dp));

  return solve(nums, 0, -1, 0);
}

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << magicalSubsequence(nums) << endl;
}