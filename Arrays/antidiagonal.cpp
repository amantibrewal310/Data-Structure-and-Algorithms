#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> diagonals(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> res(2 * n - 1, vector<int>());
    for(int i = 0; i < n; i++) {
        int l = i;
        for(int j = i; j >= 0; j--) {
            res[i].push_back(mat[l - j][j]);
        }
    }
    for(int i = 1; i < n; i++) {
        int l = n - 1;
        for(int j = i; j < n; j++) {
            res[n -1 + i].push_back(mat[j][l]);
            l--;
        }
    }

    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    vector<vector<int>> res = diagonals(mat);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}