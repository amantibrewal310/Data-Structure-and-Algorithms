//?https://www.interviewbit.com/problems/tushars-birthday-bombs/
#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int mxLen = 0;

bool check(vector<int> &a, vector<int> &b) {
  int n = a.size();

  for (int i = 0; i < n; i++) {
    if (a[i] < b[i])
      return true;
    else if (a[i] > b[i])
      return false;
  }
  return false;
}

void go(int capacity, vector<int> &powers, int i, vector<int> &curr) {
  if (capacity == 0) {
    int len = curr.size();
    if (mxLen < len) {
      mxLen = len;
      res = curr;
    } else if (mxLen == len) {
      if (check(curr, res)) {
        res = curr;
      }
    }
    return;
  }
  if (i >= powers.size()) return;
  if (powers[i] <= capacity) {
    curr.push_back(i);
    go(capacity - powers[i], powers, i, curr);
    curr.pop_back();
  }
  go(capacity, powers, i + 1, curr);
}

signed main() {
  int n, capacity;
  cin >> n >> capacity;
  vector<int> powers(n);

  for (int &power : powers) {
    cin >> power;
  }
  vector<int> curr;
  res.clear();
  mxLen = 0;
  go(capacity, powers, 0, curr);

  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}

/*
2 12
3 4

*/