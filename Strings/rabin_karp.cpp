#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7; // mod
const int P = 31; // prime number

int pow(int a, int b) {
    int res = 1;
    a %= mod;

    while(b > 0) {
        if(b & 1LL) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return pow(a, mod - 2);
}

int polyHashString(string s) {
    int hash = 0;
    int pow = 1;

    for(int i = 0; i < (int)s.length(); i++) {
        hash += ((s[i] - 'a' + 1) * pow);
        pow *= P;
        pow %= mod;
        hash %= mod;
    }

    return hash;
}

signed main() {
    string text = "abababab";
    string pat = "aba";
    int n = text.length(), m = pat.length();
    int patHash = polyHashString(pat);
    int txtHash = polyHashString(text.substr(0, m));

    

    for(int i = 1; i + m <= n; i++) {

        if(txtHash == patHash) {
            cout << i - 1 << endl;
        }

        int newHash = txtHash;

        //Step 1 : remove the i - 1 th character
        newHash = (newHash - (text[i - 1] - 'a' + 1) + mod) % mod;

        // Step 2 : left shift string (divide by the P)
        newHash = newHash * inv(P) % mod;

        // Step 3 : add the i + m - 1 character

        newHash = newHash + (text[i + m - 1] - 'a' + 1) * pow(P, m - 1);
        newHash %= mod;
        txtHash = newHash;
    }
}