#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    ?Generate Balanced Brackets using N pairs of Round Brackets
*/

void generate_brackets(string s, int n, int opnBrckts, int closeBrckts) {
    if(opnBrckts == n and closeBrckts == n) {
        cout << s << endl;
        return;
    }
    bool flag = 1;
    if(opnBrckts < n) {
        s += '(';
        generate_brackets(s, n, opnBrckts + 1, closeBrckts);
        flag = 0;
    }
    if(closeBrckts < opnBrckts) {
        if(flag == 0)
            s.pop_back();
        s += ')';
        generate_brackets(s, n, opnBrckts, closeBrckts + 1);
    }

}

signed main() {
    int n;
    cin >> n;
    generate_brackets("", n, 0, 0);
     
}