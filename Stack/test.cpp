#include <bits/stdc++.h>
using namespace std;

vector<int> kadane(vector<int> &nums) {
  int n = nums.size();
  int curr = 0;
  int mx = INT_MIN;

  int start = 0;
  int end = -1;

  vector<int> res = {-1, -1};

  for (int i = 0; i < n; i++) {
    curr += nums[i];
    if (curr > mx) {
      end = i;
      mx = curr;
      res = {start, end};
    }
    if (curr < 0) {
      curr = 0;
      start = i + 1;
    }
  }
  // cout << res[0] << " " << res[1] << endl;
  return {mx, res[0], res[1]};
}

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &num : nums) {
    cin >> num;
  }

  vector<int> temp = kadane(nums);
  int ans = temp[0];

  vector<int> t = nums;

  for (int i = 0; i < n; i++) {
    t[i] = t[i] * -1;
  }

  for (int i = 0; i < 2; i++) {
    temp = kadane(t);
    int l = temp[1];
    int r = temp[2];
    for (int j = l; j <= r; j++) {
      nums[j] = nums[j] * -1;
    }
    temp = kadane(nums);
    ans = max(ans, temp[0]);
    t = nums;
    for (int j = 0; j < n; j++) {
      t[j] = t[j] * -1;
    }
  }
  cout << ans << endl;
}