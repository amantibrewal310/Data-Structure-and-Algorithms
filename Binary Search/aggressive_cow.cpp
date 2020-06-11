//?https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int low = v[0], high = v[v.size() - 1];
        int res = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 1, left = v[0];
            for(int i = 1; i < n; i++) {
                if(v[i] - left >= mid) {
                    left = v[i];
                    cnt++;
                }
            }
            if(cnt >= c) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << res << endl;
    }
}