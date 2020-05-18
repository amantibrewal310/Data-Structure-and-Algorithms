#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> solve(vector<int> &v, int low, int high, int x) {
    vector<int> res = {-1, -1};
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return vector<int> {mid, mid};
        else if(v[mid] < x) {
            res[0] = v[mid];
            low = mid + 1;
        } else {
            res[1] = v[mid];
            high = mid - 1;
        }
    }
    return res;
}

signed main() {
    int n, key;
    cin >> n >> key;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> res = solve(v, 0, n - 1, key);
    // cout << res[0] << res[1] << endl;
    int ans = min(abs(res[0] - key), abs(res[1] - key));
    cout << ans << endl;
    
}