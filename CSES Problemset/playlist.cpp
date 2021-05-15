#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
    }

    set<int> s;
    int mx = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        s.clear();
        for (int j = 0; j < i; j++) {
            s.insert(v[j]);
        }
        for (int j = i; j < n; j++) {
            if (s.find(v[j]) != s.end()) {
                mx = max(mx, cnt);
                cnt = 0;
                s.clear();
            }
            s.insert(v[j]);
            cnt++;
        }
    }
    mx = max(mx, cnt);
    cout << mx << endl;
}