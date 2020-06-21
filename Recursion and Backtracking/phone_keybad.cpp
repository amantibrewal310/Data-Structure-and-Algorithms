#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(string in, string out, int i, int j) {
    // base case
    if(i == in.length()) {
        cout << out << endl;
        return;
    }

    int digit = in[i] - '0';
    if(digit == 1 || digit == 0) {
        generate_names(in, out, i + 1, j + 1);
    }
    for(int k = 0; k < keypad[digit].length(); k++) {
        out += keypad[digit][k];
        generate_names(in, out, i + 1, j + 1);
        out.pop_back();
    }
    return;


    // rec case
}

signed main() {
    string s;
    cin >> s;
    generate_names(s, "", 0,0);

}