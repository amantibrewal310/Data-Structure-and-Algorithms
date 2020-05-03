#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int> > generateMatrix(int n) {
    int t = 0, b = n - 1, l = 0, r = n -1 , dir = 0;
    int cnt = 1;
    vector<vector<int> > v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    while(t <= b && l <= r) {
        if(dir == 0) {
            for(int i = l; i <= r; i++) {
                v[t][i] = cnt;
                cnt++;
            }
            t++;
        }
        else if(dir == 1) {
            for(int i = t; i <= b; i++) {
                v[i][r] = cnt;
                cnt++;
            }
            r--;
        }
        else if(dir == 2) {
            for(int i = r; i >= l; i--) {
                v[b][i] = cnt;
                cnt++;
            }
            b--;
        }
        else if(dir == 3) {
            for(int i = b; i >= t; i--) {
                v[i][l] = cnt;
                cnt++;
            }
            l++;
        }
        dir = (dir + 1) % 4;
    }

    return v;
}

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> ans = generateMatrix(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}