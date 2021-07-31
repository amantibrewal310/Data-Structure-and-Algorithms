#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int x) {
  if (st.empty()) {
    st.push(x);
    return;
  }
  if (st.top() <= x) {
    st.push(x);
    return;
  }
  int top = st.top();
  st.pop();
  insert(st, x);
  st.push(top);
}

void sortStack(stack<int> &st) {
  if (st.empty()) return;
  if (st.size() == 1) return;
  int top = st.top();
  st.pop();
  sortStack(st);
  insert(st, top);
}

signed main() {
  int n;
  cin >> n;
  stack<int> st;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    st.push(a);
  }
  sortStack(st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}