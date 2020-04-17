#include<bits/stdc++.h>
using namespace std;

/*
    !Chinese Remainder Theorem 
        use to solve system of linear congurence
        i.e x % 2 = 1 is represented as 
            x = 1 (mod 2) - linear congurence
        
        For example, we have to find the x for which
            x = 1 (mod 2)
            x = 5 (mod 7)
            x = 2 (mod 3)

        ?Formula
            TODO: x = Summation of ( rem[i] * pp[i] * inv[i]) % prod
            where,
                rem[i] = array of remainders
                prod = product of no's in num[i]
                pp[i] = product of all numbers / num[i]
                inv[i] = modular multiplicative inverse of pp[i] wrt num[i]
*/
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

pair <int, int> extendedEuclid(int a, int b) {
    if(b == 0) {
        int x = 1;
        int y = 0;
        return make_pair(x, y);
    }

    pair <int, int> p = extendedEuclid(b, a % b);
    int x = p.second;
    int y = p.first - (a / b) * p.second;
    return make_pair(x, y);
}
int inverseModulo(int a, int b) {
    if(gcd(a, b) == 1) {
        int x = extendedEuclid(a, b).first;
        return (x + b) % b;
    }
    return 0;
}

int chineseRemainderTheorem(int *num, int *rem, int n) {

    int prod = 1;
    for(int i = 0; i < n; i++) {
        prod = prod * num[i];
    }

    int pp[n];
    for(int i = 0; i < n; i++) {
        pp[i] = prod / num[i];
    }

    int inv[n];
    for(int i = 0; i < n; i++) {
        inv[i] = inverseModulo(pp[i], num[i]);
    }

    int x = 0;
    for(int i = 0; i < n; i++) {
        x += (rem[i] * pp[i] * inv[i]) % prod;
    }

    return x;
}
signed main() {

    int n;
    cin >> n;
    int num[n];
    int rem[n];

    for(int i = 0; i < n; i++)
        cin >> num[i];

    for(int i = 0; i < n; i++)
        cin >> rem[i];
    
    cout << chineseRemainderTheorem(num, rem, n) << "\n";
}