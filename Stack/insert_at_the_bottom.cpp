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

signed main() {
  int n, x;
  cin >> n >> x;
  stack<int> st;

  while (n--) {
    int a;
    cin >> a;
    st.push(a);
  }
  insertAtTheBottom(st, x);
}