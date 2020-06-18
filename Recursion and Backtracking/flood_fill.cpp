#include<bits/stdc++.h>
using namespace std;
#define int long long

void floodFill(vector<vector<int>> &a, int r, int c, int toFill, int prevFill) {
    int rows = a.size();
    int cols = a[0].size();

    if(r < 0 || r >= rows || c < 0 || c >= cols)
        return;
    if(a[r][c] != prevFill)
        return;
    if(a[r][c] == toFill)
        return;
    
    a[r][c] = toFill;
    floodFill(a, r - 1, c, toFill, prevFill);
    floodFill(a, r, c - 1, toFill, prevFill);
    floodFill(a, r + 1, c, toFill, prevFill);
    floodFill(a, r, c + 1, toFill, prevFill);
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    int prevFill, toFill;
    cin >> prevFill >> toFill;
    floodFill(v, 0, 0, toFill, prevFill);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}