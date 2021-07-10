//?https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {
  int pivot = a[r];
  int i = l - 1;

  for (int j = l; j <= r - 1; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i + 1], a[r]);
  return i + 1;
}

int solve(vector<int> &nums, int k) {
  int low = 0;
  int high = nums.size() - 1;

  // int p = partition(nums, low, high);

  while (low <= high) {
    int mid = partition(nums, low, high);

    if (mid + 1 == k)
      return nums[mid];
    else if (mid + 1 > k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return nums[low];
}

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);

  for (auto &num : nums) {
    cin >> num;
  }

  cout << solve(nums, k) << endl;
}

/*
6 3
7 10 4 3 20 15

*/