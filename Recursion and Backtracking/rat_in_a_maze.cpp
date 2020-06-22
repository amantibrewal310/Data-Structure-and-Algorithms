#include<bits/stdc++.h>
using namespace std;


bool ratInMaze(vector<vector<int>> &maze, int i, int j, int m, int n, vector<vector<int>> sol) {
    if(i == m and j == n) {
        sol[m][n] = 1;
        //Print the path
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    // Rat should be inside grid
    if(i > m || j > n) 
        return false;
    if(maze[i][j] == 1)
        return false;
    
    // Assume solution exists through current cell
    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, i, j + 1, m, n, sol);
    bool downSuccess = ratInMaze(maze, i + 1, j, m, n, sol);

    // Backtracking
    sol[i][j] = 0;

    if(rightSuccess || downSuccess)
        return true;
    return false;
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>>sol(rows, vector<int>(cols, 0));
    bool ans = ratInMaze(mat, 0, 0, rows - 1, cols - 1, sol);

    if(ans == false) 
        cout << "Path does not exits" << endl;
}