//?https://www.interviewbit.com/problems/chain-of-pairs/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &nums, int i) {
  int n = nums.size();
  if (i >= n) return 0;

  int ans = solve(nums, i + 1);

  vector<int> val = {nums[i][1], INT_MAX, nums[i][2]};

  int j = upper_bound(nums.begin() + i, nums.end(), val) - nums.begin();

  cout << "i:" << i << " j: " << j << endl;

  if (j != n) {
    if (nums[j][2] > nums[i][2]) {
      int temp = solve(nums, j) + 1;
      ans = max(ans, temp);
    }
  }

  return ans;
}

signed main() {
  int n;
  cin >> n;

  vector<vector<int>> a;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y, i});
  }
  sort(a.begin(), a.end());
  cout << solve(a, 0) << endl;
}

/*
98 894
397 942
70 519
258 456
286 449
516 626
370 873
214 224
74 629
265 886
708 815
394 770
56 252

5
5 24
39 60
15 28
27 40
50 90

*/