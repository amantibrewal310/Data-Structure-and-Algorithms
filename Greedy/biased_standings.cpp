//?https://www.spoj.com/problems/BAISED/
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, string>> v(n);

        for(auto &p : v) {
            cin >> p.second >> p.first;
        }
        sort(v.begin(), v.end(), cmp);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            // cout << v[i].first << endl;
            ans += abs((i + 1 - v[i].first));
        }
        cout << ans << endl;
    }

}