#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> getRow(int n) {
    vector<int> res;
    int x = 1;
    for(int i = 0; i <= n; i++) {
        res.push_back(x);
        x = x * (n - i) / (i + 1);
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    auto res = getRow(n);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}