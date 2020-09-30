//?https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string/0/?company[]=SAP%20Labs&page=1&query=company[]SAP%20Labspage1
#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int sum = 0;
        string tmp = "";
        int len = s.length();

        for(int i = 0; i < len; i++) {
            if(isdigit(s[i])) {
                // cout << s[i] << "--";
                // cout << tmp << endl;
                tmp += s[i];
                continue;
            }
            if(tmp.length() != 0) {
                stringstream ss(tmp);
                int num;
                ss >> num;
                sum += num;
                tmp = "";
            }
            
        }
        if(tmp.length() != 0) {
            stringstream ss(tmp);
            int num;
            ss >> num;
            sum += num;
            tmp = "";
        }
        cout << sum << endl;
    }
}