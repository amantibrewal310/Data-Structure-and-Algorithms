#include <bits/stdc++.h>
using namespace std;

bool redundantBraces(string &s) {
  stack<char> st;
  set<char> operators = {'+', '-', '*', '/'};

  for (auto c : s) {
    if (c == ')') {
      if (!st.empty() and st.top() == '(') return true;
      bool isOperator = false;
      while (!st.empty() and st.top() != '(') {
        if (operators.find(st.top()) != operators.end()) {
          isOperator = true;
        }
        st.pop();
      }
      st.pop();
      if (!isOperator) return true;
    } else {
      st.push(c);
    }
  }
  return 0;
}

signed main() {
  string s;
  cin >> s;
  cout << redundantBraces(s) << endl;
}