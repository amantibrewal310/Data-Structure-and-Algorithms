#include <bits/stdc++.h>
using namespace std;

void insertAtTheBottom(stack<int> &st, int x) {
  if (st.empty()) {
    st.push(x);
    return;
  }
  int temp = st.top();
  st.pop();
  insertAtTheBottom(st, x);
  st.push(temp);
}

// Time Complexity - O(N ^ 2)
// Space Complexity - O(N)

void reverse(stack<int> &st) {
  if (st.empty()) return;
  int x = st.top();
  st.pop();
  reverse(st);
  insertAtTheBottom(st, x);
}

signed main() {
  int n;
  cin >> n;

  stack<int> st;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
  }

  reverse(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}