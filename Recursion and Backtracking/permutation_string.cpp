#include<bits/stdc++.h>
using namespace std;

void permutationString(string s, int l, int r) {
    if(l == r) {
        cout << s << endl;
        return;
    }
    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permutationString(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

signed main() {
    string s;
    cin >> s;
    int n = s.length();
    permutationString(s, 0, n - 1);

}