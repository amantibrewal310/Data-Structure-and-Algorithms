#include<bits/stdc++.h>
using namespace std;
#define int long long

void generate_subsequence(string s, string out, int i) {
    if(i == s.length()) {
        cout << out << endl;
        return;
    }
    out += s[i];
    generate_subsequence(s, out, i + 1);
    out.pop_back();
    generate_subsequence(s, out, i + 1);
}

signed main() {
    string s;
    cin >> s;
    generate_subsequence(s, "", 0);
}