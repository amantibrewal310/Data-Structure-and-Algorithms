//?https://www.interviewbit.com/problems/merge-elements/
#include <bits/stdc++.h>
using namespace std;

int dp[201][201];
int prefixSum[201];

int minCost(vector<int> &nums, int i, int j) {
  if (i > j) return 0;
  if (i == j) return 0;
  if (i == j + 1) return nums[i] + nums[j];

  if (dp[i][j] != -1) return dp[i][j];

  int ans = INT_MAX;
  int sum = 0;
  int total = 0;
  for (int k = i; k <= j; k++) {
    total += nums[k];
  }
  for (int k = i; k < j; k++) {
    sum += nums[k];
    int leftCost = minCost(nums, i, k);
    int rightCost = minCost(nums, k + 1, j);
    ans = min(ans, leftCost + rightCost + total);
  }
  return dp[i][j] = ans;
}
signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for (int &num : nums) {
    cin >> num;
  }
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    prefixSum[i] = sum + nums[i];
    sum += nums[i];
  }
  for (int i = 0; i < n; i++) {
    cout << prefixSum[i] << " ";
  }
  cout << endl;
  cout << minCost(nums, 0, n - 1) << endl;
}