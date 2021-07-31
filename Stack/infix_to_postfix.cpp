#include <bits/stdc++.h>
using namespace std;

/*
  Left to right scan
  - if operand
      print
  - if '('
      push to stack
  - if ')'
      pop from the stack until '(' found
  - if operator
      pop and print until you found operator with less precendence


  PRECEDENCE
    - Exponentiation ('^')
    - Multiplication and Division
    - Addition and Subtraction
*/

int getPrecendence(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' or c == '/') {
    return 2;
  } else if (c == '+' or c == '-') {
    return 1;
  }
  return -1;
}

string infixToPostFix(string &s) {
  stack<char> st;

  string res = "";

  for (int i = 0; i < s.length(); i++) {
    if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) {
      res += s[i];
    } else if (s[i] == '(') {
      st.push(s[i]);
    } else if (s[i] == ')') {
      while (st.top() != '(') {
        res += st.top();
        st.pop();
      }
      st.pop();
    } else {
      int prec = getPrecendence(s[i]);
      while (!st.empty() and prec < getPrecendence(st.top())) {
        res += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while (!st.empty()) {
    res += st.top();
    st.pop();
  }
  return res;
}

signed main() {
  string s;
  cin >> s;

  cout << infixToPostFix(s) << endl;
}

/*
  (a-b/c)*(a/k-l)
*/