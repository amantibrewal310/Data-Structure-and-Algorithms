#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToRight(vector<int> &nums) {
  int n = nums.size();

  stack<int> st;
  vector<int> res(n);

  for (int i = n - 1; i >= 0; i--) {
    if (st.empty()) {
      res[i] = -1;
    } else if (nums[i] > nums[st.top()]) {
      res[i] = st.top();
    } else {
      while (!st.empty() and nums[i] <= nums[st.top()]) {
        st.pop();
      }
      if (st.empty()) {
        res[i] = -1;
      } else {
        res[i] = st.top();
      }
    }
    st.push(i);
  }
  return res;
}

vector<int> nextSmallerToLeft(vector<int> &nums) {
  int n = nums.size();

  stack<int> st;
  vector<int> res(n);

  for (int i = 0; i < n; i++) {
    if (st.empty()) {
      res[i] = -1;
    } else if (nums[i] > nums[st.top()]) {
      res[i] = st.top();
    } else {
      while (!st.empty() and nums[i] <= nums[st.top()]) {
        st.pop();
      }
      if (st.empty()) {
        res[i] = -1;
      } else {
        res[i] = st.top();
      }
    }
    st.push(i);
  }
  return res;
}

int largestRectangleArea(vector<int> &heights) {
  vector<int> left = nextSmallerToLeft(heights);
  vector<int> right = nextSmallerToRight(heights);

  int ans = 0;
  int n = heights.size();

  for (int i = 0; i < heights.size(); i++) {
    int l = left[i] != -1 ? left[i] : -1;
    int r = right[i] != -1 ? right[i] : n;

    int width = r - l - 1;

    int area = heights[i] * width;
    ans = max(ans, area);
    ans = max(ans, heights[i]);
  }
  return ans;
}

signed main() {
  int n;
  cin >> n;
  vector<int> heights(n);

  for (auto &height : heights) {
    cin >> height;
  }
  cout << largestRectangleArea(heights) << endl;
}