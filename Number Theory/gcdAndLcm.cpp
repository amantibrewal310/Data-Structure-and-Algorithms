#include<bits/stdc++.h>
using namespace std;

// GCD is calculated using Euclid's Methods
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    int lcm = a * b / gcd(a, b);
    return lcm;
}

signed main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
}