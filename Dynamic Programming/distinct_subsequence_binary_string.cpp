#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int countSub(string s) {
  map<char, int> Map;
  for (int i = 0; i < s.length(); i++) {
    Map[s[i]] = -1;
  }
  int allCount = 0;
  int levelCount = 0;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    levelCount = (allCount + (c == '1' ? 1 : 0)) % mod;
    if (Map[c] < 0) {
      allCount = (allCount + levelCount) % mod;
    } else {
      allCount = (allCount + levelCount - Map[c]) % mod;
    }
    Map[c] = levelCount;
  }
  return allCount;
}

int32_t main() {
  string s;
  cin >> s;

  int zero = 0;
  for (auto it : s)
    if (it == '0') zero = 1;
  cout << countSub(s) + zero << '\n';
}