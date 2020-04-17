#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 10e9 + 7;

/*
    ?Light new car
    The price of car is A, now it become A ** 2 on next day and A ** 3 
    on third day and so on...
    
    !Task: 
        We need to calculate the price on the Bth day modulo 10e9 + 7
    !Constraint:
        1 <= A, B <= 10e10e5 i.e around 10 ** 5 digits;

*/

int stringToInt(string a, int mod) {

    int num = 0;

    for(int i = 0; i < a.size(); i++) {
        num = (num * 10) % mod + (a[i] - '0');
        num %= mod;
    }

    return num;
}

int power(int x, int y, int mod) {
    if(y == 0) {
        return 1;
    }

    int k = power(x, y /2, mod);
    k %= mod;
    int smallPower = ( (k % mod) * (k % mod) ) % mod;

    if(y & 1)
        return ( (x % mod) * (smallPower % mod) ) % mod;

    else
        return smallPower;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        

        // String into integers
        int x = stringToInt(a, mod);
        int y = stringToInt(b, mod - 1);

        // Power x ** y
        int ans = power(x, y, mod);
        cout << ans << endl;
    }
}