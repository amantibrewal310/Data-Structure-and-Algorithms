#include<bits/stdc++.h>
using namespace std;
#define int long long

int coverPoints(vector<int> &a, vector<int> &b) {
    int cnt = 0;
    int x = a[0], y = b[0];
    for(int i = 1; i < a.size(); i++) {
        cnt += max(abs(a[i] - x),abs(b[i] - y));
        x = a[i];
        y = b[i];
    }

    return cnt;
}

signed main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout << coverPoints(x, y) << endl;

}