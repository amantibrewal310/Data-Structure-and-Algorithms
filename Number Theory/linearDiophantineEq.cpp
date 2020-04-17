#include<bits/stdc++.h>
using namespace std;

/*
    ?Linear Diophantine Equations

        A Dophantine equations is a polynomial equation, usually in two
        or more unknowns, such that only the integral solutions are
        required. An Integral solution is a solution such that all the unknown variables take only integer values.

        Given three integers a, b, c representing a linear equation of
        the form : ax + by = c. Determine if the equation has a solution such that x and y are both integral values.

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

void solveLinearDiophantineEq(int a, int b, int c) {
    int k = gcd(a, b);
    if(c % k == 0) {
        pair <int, int> ans = extendedEucildMethod(a, b);
        ans.first = ans.first * (c / k);
        ans.second = ans.second * (c / k); 

        cout << ans.first << " " << ans.second << "\n";
    }
}

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    pair <int, int> p = extendedEucildMethod(a, b);
    solveLinearDiophantineEq(a, b, c);
}