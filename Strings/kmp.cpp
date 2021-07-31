#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string &s) {
  int n = s.length();
  int i, j = i = 0;

  // i -> means current index of the string
  // j -> means that prefix of length j is also suffix of that string

  vector<int> lps(n);
  lps[0] = 0;
  i = 1, j = 0;
  while (i < n) {
    if (s[i] == s[j]) {
      lps[i] = j + 1;
      i++;
      j++;
    } else if (j != 0) {
      j = lps[j - 1];
    } else {
      lps[i] = 0;
      i++;
    }
  }
  return lps;
}

signed main() {
  string s;
  cin >> s;
}