#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    Replace "Pi" with "3.14"
    Xpixx ---> X3.14xx

*/

void replacePi(string &s, int i) {
    if(i == s.length() - 1) {
        return;
    }

    // look for pi for current location
    if(s[i] == 'p' and s[i + 1] == 'i') {
        //shifting + replacement with 3.14
        string s1 = s.substr(0, i);
        string s2 = s.substr(i + 2);
        s = s1 + "3.14" + s2;
        replacePi(s, i + 2);

    } else {
        // go to the next position
        replacePi(s, i + 1);
    }
    return;
}

signed main() {
    string s;
    cin >> s;
    replacePi(s, 0);
    cout << s << endl;
}