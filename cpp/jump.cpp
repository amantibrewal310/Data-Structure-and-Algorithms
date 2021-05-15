#include<bits/stdc++.h>
using namespace std;

signed main() {
    
    int n;
    cin >> n;
    if(n % 2 == 0) {
        goto even;
    }
    else
        goto odd;
    
    even:
        cout << "even" << endl;
        return 0;
    odd:
        cout << "odd" << endl;
        return 0;
}       