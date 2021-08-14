#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string &s) {
  int n = s.length();
  int i, j;
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

// method 1
vector<int> solve(string &text, string &pattern) {
  vector<int> lps = computeLPS(pattern);

  int n = text.size();
  int m = pattern.size();
  vector<int> res;

  int i = 0, j = 0;

  while (i < n) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else if (j == 0) {
      i++;
    } else {
      j = lps[j - 1];
    }
    if (j == m) {
      res.push_back(i - m);
    }
  }
  return res;
}

// method 2
vector<int> solve2(string &text, string &pattern) {
  string s = pattern + '&' + text;

  vector<int> lps = computeLPS(s);
  vector<int> res;

  int m = pattern.size();
  for (int i = m + 1; < s.length(); i++) {
    if (lps[i] == m) {
      res.push_back(i - m + 1 - (m + 1));
    }
  }
  return res;
}

signed main() {
  string text, pattern;
  cin >> text >> pattern;

  vector<int> res = solve(text, pattern);

  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;

  res = solve2(text, pattern);

  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
}