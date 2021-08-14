#include <bits/stdc++.h>
using namespace std;

bool isPre(string a, string b) {
  int n = b.length();
  int m = a.length();

  if (m < n) return false;

  for (int i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

string solve(vector<string> &menu, string input) {
  int n = menu.size();

  map<char, int> freq;

  for (int i = 0; i < n; i++) {
    if (isPre(menu[i], input)) {
      freq[menu[i][input.length()]]++;
    }
  }

  for (auto p : freq) {
    cout << p.first << " " << p.second << endl;
  }

  return "";
}

signed main() {
  int n;
  cin >> n;
  vector<string> menu(n);

  for (int i = 0; i < n; i++) {
    cin >> menu[i];
  }
  string input;
  cin >> input;
  cout << solve(menu, input) << endl;
}