//?https://www.interviewbit.com/problems/partitions/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &nums) {
  vector<int> prefix(n);
  prefix[0] = nums[0];
  map<int, int> freq;

  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + nums[i];
  }

  int res = 0;

  for (int i = 0; i < n - 1; i++) {
    int sum = prefix[i];
    if (sum % 2) {
      freq[prefix[i]]++;
      continue;
    };
    sum = sum / 2;
    if (prefix[n - 1] - prefix[i] != sum) {
      freq[prefix[i]]++;
      continue;
    };
    if (freq.find(sum) != freq.end()) {
      res += freq[sum];
    }
    freq[prefix[i]]++;
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for (auto &num : nums) {
    cin >> num;
  }
  cout << solve(n, nums) << endl;
}