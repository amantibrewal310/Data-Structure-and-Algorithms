#include<bits/stdc++.h>
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void generate_string(string s,string out, int n, int i) {
    if(i == n) {
        cout << out << endl;
        return;
    }
    int digit1 = s[i] - '0';
    out += alpha[digit1 - 1];
    generate_string(s, out, n, i + 1);
    if(i + 1 == n)
        return;

    int digit2 = s[i + 1] - '0';
    int num = digit1 * 10 + digit2;
    if (num <= 26)
    {
        out.pop_back();
        out += alpha[num - 1];
        generate_string(s, out, n, i + 2);
    }
}

signed main() {
    string s;
    cin >> s;
    generate_string(s, "", s.length(), 0);


}