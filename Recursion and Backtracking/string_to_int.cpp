#include<bits/stdc++.h>
using namespace std;

int stringToInt(string s) {
    int n = s.length();
    if(n == 1) {
        return s[0] - '0';
    }
    string str = s.substr(0, n - 1);
    return stringToInt(str) * 10 + stringToInt(s.substr(n - 1, 1));
}

signed main() {
    string s;
    cin >> s;
    cout << stringToInt(s) << endl;

}