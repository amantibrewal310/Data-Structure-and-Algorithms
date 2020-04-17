#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    Fast Modulo Exponential using Bitmasks
        Time Complexity : O(logb)
    
*/

int fastModExp(int a, int b, int m) {
    
    int res = 1;

    while(b > 0) {

        if(b & 1) {
            res = ( (res % m) * (a % m) ) % m;
        }

        a = ( (a % m) * (a % m) ) % m;
        b = b >> 1;
    }

    return res % m;
}

signed main() {

    int a , b, m;
    cin >> a >> b >> m;
    
    cout << fastModExp(a, b, m) << "\n";

}