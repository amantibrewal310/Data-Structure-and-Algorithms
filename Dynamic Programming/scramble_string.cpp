#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t) {
  int n = s.length();
  int m = t.length();

  if (n != m) return false;
  if (s == t) return true;
  if (n == 0 or m == 0) return false;

  for (int i = 0; i < n - 1; i++) {
    string p = s.substr(0, i + 1);
    string q = t.substr(m - (i + 1));
    if (solve(p, q) and solve(s.substr(i + 1), t.substr(0, m - (i + 1))))
      return true;

    if (solve(s.substr(0, i + 1), t.substr(0, i + 1)) and
        solve(s.substr(i + 1), t.substr(i + 1))) {
      return true;
    }
  }
  return false;
}

signed main() {
  string s, t;
  cin >> s >> t;
  cout << solve(s, t) << endl;
}

/*
abbbcbaaccacaacc
acaaaccabcabcbcb

knxhpkpcogzwrwdyfksw
fpsprgdywowkckhzxnkw

*/