#include<bits/stdc++.h>
using namespace std;
#define int long long
int rows, cols, maxSize = 0;
vector<vector<int>> visited;


vector<vector<int> > dir {
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}
};

bool validate(int i, int j) {
    if(i >= 0 && i < rows && j >= 0 && j < cols)
        return true;
    return false;
}

void findMaxBlock(vector<vector<int> > &mat, int r, int c, int size) {

    if(!validate(r, c))
        return;
    
    visited[r][c] = 1;
    size += 1;
    maxSize = max(maxSize, size);

    for(int i = 0; i < 8; i++) {
        int new_r = r + dir[i][0];
        int new_c = c + dir[i][1];
        if(validate(new_r, new_c) && mat[new_r][new_c] > 0 && visited[new_r][new_c] == 0)
            findMaxBlock(mat, new_r, new_c, size);
    }
    visited[r][c] = 0;
}

int maxOnes(vector<vector<int>> &mat) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] == 1)
                findMaxBlock(mat, i, j, 0);
        }
    }
    return maxSize;
}

signed main() {
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    visited.assign(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];
    }

    cout << maxOnes(mat) << endl;
}