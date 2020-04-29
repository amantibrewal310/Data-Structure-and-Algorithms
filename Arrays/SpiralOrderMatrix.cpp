#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> spiralOrder(const vector<vector<int> > & mat) {
    int rows = mat.size();
    if(rows == 0)
        return vector<int>();
    
    int cols = mat[0].size();
    vector<int> result;
    result.resize(rows * cols);

    int t = 0, l = 0, b = rows - 1, r = cols - 1, dir = 0, n = -1;

    while(t <= b && l <= r) {
        if(dir == 0) {
            for(int i = l; i <= r; i++)
                result[++n] = mat[t][i];
            t++;
        }
        else if(dir == 1) {
            for(int i = t; i <= b; i++)
                result[++n] = mat[i][r];
            r--;
        }
        else if(dir == 2) {
            for(int i = r; i >= l; i--)
                result[++n] = mat[b][i];
            b--;
        }
        else if(dir == 3) {
            for(int i = b; i >= t; i--)
                result[++n] = mat[i][l];
            l++;
        }

        dir = (dir + 1) % 4;
    }
    return result;
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;
    vector< vector<int> > mat(rows, vector<int> (cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> result = spiralOrder(mat);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}