#include<bits/stdc++.h>
using namespace std;

/*
    ?Extended Euclid's Algorithms
    Ax + By = GCD(A, B)

    We need to find (x, y)

    !Major Applocations:
        1. Multiplicative Modulo Inverse
        2. Linear Diophantine Equations

*/
pair <int, int> extendedEuclid(int a, int b) {
    pair <int, int> p;
    if(b == 0) {
        p.first = 1;
        p.second = 0;
        return p;
    }
    p = extendedEuclid(b, a % b);
    int x = p.second;
    int y = p.first - (a / b) * p.second;
    p = make_pair(x, y);
    return p;

}

signed main() {

    int a, b;
    cin >> a >> b;
    pair <int, int> ans = extendedEuclid(a, b);
    cout << ans.first << " " << ans.second << endl;

}