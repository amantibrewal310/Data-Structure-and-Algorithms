//?https://www.spoj.com/problems/BUSYMAN/
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);

        for(auto &p : v) {
            cin >> p.first >> p.second;
        }

        sort(v.begin(), v.end(), cmp);
        int cnt = 1;
        int prev = v[0].second;
        for(int i = 1; i < n; i++) {
            if(v[i].first >= prev) {
                cnt++;
                prev = v[i].second;
            }
        }
        cout << cnt << endl;
    }

}