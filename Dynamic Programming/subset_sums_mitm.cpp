//?https://www.spoj.com/problems/SUBSUMS/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> &nums, int l, int r) {
  int n = nums.size();

  vector<int> left, right;
  left.push_back(0);
  right.push_back(0);

  for (int i = 0; i <= n / 2; i++) {
    vector<int> temp;

    for (auto ele : left) {
      temp.push_back(ele + nums[i]);
    }

    for (auto ele : temp) {
      left.push_back(ele);
    }
  }
  for (int i = (n / 2) + 1; i < n; i++) {
    vector<int> temp;
    for (auto ele : right) {
      temp.push_back(ele + nums[i]);
    }

    for (auto ele : temp) {
      right.push_back(ele);
    }
  }
  sort(right.begin(), right.end());

  int ans = 0;

  for (auto ele : left) {
    int lower =
        lower_bound(right.begin(), right.end(), l - ele) - right.begin();
    int upper =
        upper_bound(right.begin(), right.end(), r - ele) - right.begin();

    ans += (upper - lower);
  }
  return ans;
}

signed main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << solve(nums, l, r) << endl;
}