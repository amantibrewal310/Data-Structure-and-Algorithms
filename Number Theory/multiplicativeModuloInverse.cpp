#include<bits/stdc++.h>
using namespace std;

/*
    Multiplicative Modulo Inverse
        (a * b) % MOD = 1
            Given is a find b
    Efficient way is to use Extended Version of Euclid's Algorithms.
    !IMPORTANT POINT:
        Modulo Inverse only exist if and only if
            GCD(a, MOD) = 1
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); 
}

pair <int, int> extendedEucildMethod(int a, int b) {
    if(b == 0) {
        int x = 1;
        int y = 0;

        return make_pair(x, y);
    }

    pair <int, int> p = extendedEucildMethod(b, a % b);
    int x = p.second;
    int y = p.first - (a / b) * p.second;

    return make_pair(x, y);
}

int inverseModulo(int a, int mod) {

    if(gcd(a, mod) == 1) {
        int x = extendedEucildMethod(a, mod).first;
        return (x + mod) % mod;
    }

    return 0;
}

signed main() {
    int a, mod;
    cin >> a >> mod;
    cout << inverseModulo(a, mod) << endl;
    
}
