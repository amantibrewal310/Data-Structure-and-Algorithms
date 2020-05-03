#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int> > solve(int n) {
    vector<vector<int> > v(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(v[i].size() == 0) {
                v[i].push_back(1);
            }
            else if(v[i].size() == i) {
                v[i].push_back(1);
            }
            else {
                int x = v[i - 1][j - 1] + v[i - 1][j];
                v[i].push_back(x);
            }
        }
    }

    
    return v;
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int> > v = solve(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}