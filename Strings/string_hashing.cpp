#include<bits/stdc++.h>
using namespace std;
#define int long long

int polyHashString(string s) {
    int p = 31; // prime number
    int mod = 1e9 + 7; // mod;
    int  pow = 1;
    int hash = 0;

    for(int i = 0; i < s.length(); i++) {
        hash += (pow * (s[i] - 'a' + 1));
        pow *= p;
        pow %= mod;
        hash %= mod;
    }

    return hash;
}

signed main() {
    string s = "abababab";

    int hash = polyHashString(s);
    cout << hash << endl;
}