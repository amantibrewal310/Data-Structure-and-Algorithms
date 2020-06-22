#include<bits/stdc++.h>
using namespace std;
#define int long long

bool canPlace(vector<vector<int>> mat, int i, int j, int n, int num) {
    for(int k = 0; k < n; k++) {
        if(k != j) {
            if(mat[i][k] == num)
                return false;
        }
    }
    for(int k = 0; k < n; k++) {
        if(k != i) {
            if(mat[k][j] == num)
                return false;
        }
    }
    int rootN = sqrt(n);
    int sx = (i / rootN) * rootN;
    int sy = (j / rootN) * rootN;

    for(int x = sx; x < sx + rootN; x++) {
        for(int y = sy; y < sy + rootN; y++) {
            if(mat[x][y] == num)
                return false;
        }
    }
    return true;
}
void printSudoku(vector<vector<int>> mat) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveSudoku(vector<vector<int>> mat, int i, int j, int n) {
    // Base Case
    if(i == n) {
        //Print the solution
        printSudoku(mat);
        return true;
    }

    // Case Row End
    if(j == n) {
        return solveSudoku(mat, i + 1, 0, n);
    }

    // Skip the Pre-filled Cells
    if(mat[i][j] != 0) {
        return solveSudoku(mat, i, j + 1, n);
    }
    // Recursive Case
    // Fill the current cell with possible options
    for(int num = 1; num  <= n; num++) {
        if(canPlace(mat, i, j, n, num)) {
            mat[i][j] = num;
            if(solveSudoku(mat, i, j + 1, n))
                return true;
            // mat[i][j] = 0;
        }
    }
    // Backtrack Here
    mat[i][j] = 0;
    return false;
}

signed main() {

    vector<vector<int>> mat(9, vector<int>(9, 0));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = solveSudoku(mat, 0, 0, 9);
    if(!ans)
        cout << "Sudoku cannot be solved" << endl;

}