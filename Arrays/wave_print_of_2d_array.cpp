#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Wave Print
    for(int col = 0; col < m; col++) {
        if(col % 2 == 0) {
            // Even Col - Top Down
            for(int row = 0; row < n; row++) {
                cout << a[row][col] << " ";
            }
        }
        else {
            // Bottom up direction
            for(int row = n - 1; row >= 0; row--) {
                cout << a[row][col] << " ";
            }
        }
    }
    cout << endl;
}