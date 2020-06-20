#include<bits/stdc++.h>
using namespace std;
/*
    ? Count Binary Strings
    -----------------------
    Count Binary Strings of Length of N, Which have No consecutive ones ?

*/

int cnt(int n) { 
    if(n == 1)
        return 2;
    if(n == 2)
        return 3;
    return cnt(n -1) + cnt(n - 2);
    
}

void findBinary(string s, int n, int i) {
    if(i == n) {
        cout << s << endl;
        return;
    }
    s[i] = '0';
    findBinary(s, n, i + 1);
    if(i == 0) {
        s[i] = '1';
        findBinary(s, n, i + 1);
    }
    if(i != 0 and s[i - 1] != '1') {
        s[i] = '1';
        findBinary(s, n, i + 1);
    }
}

signed main() {
    int n;
    cin >> n;
    cout << cnt(n) << endl;
    string s(n ,'0');
    findBinary(s, n, 0);
}