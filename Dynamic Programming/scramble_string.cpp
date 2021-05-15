#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t, int i, int j) {
    if (i > j) return false;

    if (s.substr(i, j - i) == t.substr(i, j - i)) return 1;

    for (int k = i; k <= j; k++) {
    }
}

signed main() {
    string s, t;
    cin >> s >> t;
}