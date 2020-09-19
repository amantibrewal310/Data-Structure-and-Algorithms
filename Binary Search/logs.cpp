//?https://atcoder.jp/contests/abc174/tasks/abc174_e
#include<bits/stdc++.h>
using namespace std;

bool isValid(int n, int m, int k) {
    if((n / m) - 1 <= k)
        return true;
    return false;
}

signed main() {
    int n, k;
    cin >> n >> k;

    int low = 0;
    int high = n;
    int ans = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isValid(n, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}