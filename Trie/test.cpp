#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
                cnt++;
            }
        }

        if(cnt == 0) {
            if(n % 2) {
                cout << "A" << endl;
            } else {
                cout << "B" << endl;
            }
        } else {
            int k = n - cnt + 1;
            if(k % 2 == 0) {
                cout << "A" << endl;
            } else {
                cout << "D" << endl;
            }
        }
    }
}