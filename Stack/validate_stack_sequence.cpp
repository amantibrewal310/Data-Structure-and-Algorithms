//?https://leetcode.com/problems/validate-stack-sequences/
#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  int n = pushed.size();
  int i = 0;
  int j = 0;
  stack<int> st;

  while (i < n) {
    int ele = pushed[i];
    if (ele != popped[j]) {
      st.push(ele);
    } else {
      j++;
      while (!st.empty() and st.top() == popped[j]) {
        j++;
        st.pop();
      }
    }
    i++;
  }
  return j == n;
}

signed main() {
  int n;
  cin >> n;
  vector<int> pushed(n), popped(n);

  for (int i = 0; i < n; i++) {
    cin >> pushed[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> popped[i];
  }
  cout << validateStackSequences(pushed, popped) << endl;
}

/*
5
7 2 9 4 5
4 5 9 2 7

*/