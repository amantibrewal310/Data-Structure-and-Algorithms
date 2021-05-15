#include<bits/stdc++.h>
using namespace std;


int closestNumber(int n, int m) {
    int q = n / m;
    int n1 = q * m;
    int n2 = (n * m) > 0 ? (m * (q + 1) ) : (m * (q - 1) );

    if(abs(n - n1) < abs(n - n2) )
        return n1;
    else 
        return n2;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << closestNumber(n, m) << endl;
    }
}