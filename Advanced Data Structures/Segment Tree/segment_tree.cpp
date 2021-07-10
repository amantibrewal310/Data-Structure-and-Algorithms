//! https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/

#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e5 + 2;
int tree[4 * MAX_SIZE];

int merge(int l, int r) { return l + r; }

void buildSegTree(vector<int> &nums, int treeIndex, int l, int r) {
  if (l == r) {  // LEAF NODE
    tree[treeIndex] = nums[l];
    return;
  }

  int mid = l + (r - l) / 2;
  buildSegTree(nums, 2 * treeIndex + 1, l, mid);
  buildSegTree(nums, 2 * treeIndex + 2, mid + 1, r);

  tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

int querySegTree(int treeIndex, int l, int r, int i, int j) {
  if (l > j || r < i)  // Segment Completely outside range
    return 0;
  if (i <= l and j >= r)  // segment completely inside range
    return tree[treeIndex];

  int mid =
      l + (r - l) / 2;  // partial overlap of current segment and queried range.

  if (i > mid) {
    return querySegTree(2 * treeIndex + 2, mid + 1, r, i, j);
  }
}

signed main() {
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int &num : nums) {
    cin >> num;
  }

  buildSegTree(nums, 0, 0, n - 1);

  for (int i = 0; i < 25; i++) {
    cout << tree[i] << " ";
  }
  cout << endl;
}

/*
{ 18, 17, 13, 19, 15, 11, 20, 12, 33, 25 }
10
18 17 13 19 15 11 20 12 33 25

*/