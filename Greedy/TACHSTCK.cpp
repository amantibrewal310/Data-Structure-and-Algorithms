//?https://www.codechef.com/problems/TACHSTCK
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    int i = 0;
    int cnt = 0;
    while(i < n - 1) {
        if(v[i + 1] - v[i] <= d) {
            cnt++;
            i = i + 2;
            continue;
        }
        i++;
    }
    cout << cnt << endl;
}