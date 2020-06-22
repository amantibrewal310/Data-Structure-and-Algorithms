#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> board, int i, int j, int n) {
    // check for col
    for(int row = 0; row < i; row++) {
        if(board[row][j] == 1)
            return false;
    }

    // check for Left Diagonal
    int x = i;
    int y = j;

    while(x >= 0 and y >= 0) {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for right diagonal
    x = i;
    y = j;
    while(x >= 0 and y < n) {
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    // The position is now safe
    return true;
}

void print(vector<vector<int>> &board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 1)
                cout << "Q ";
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}

bool solveNQueen(vector<vector<int>> &board, int i, int n) {
    // Base Case
    if(i == n) {
        // You have successfully place queens in n rows;
        // Print the board

        print(board);
        return true; // !If we change it to false than we will get all the possible configurations
    }
    // Rcursive Case
    // Try to place the queen in the current row and call on the remaing part which will be solved by recursion

    for(int j = 0; j < n; j++) {
        // I have to check if i, jth position is safe to place or not
        // For that we need to check diagonally only and upward
        if(isSafe(board, i, j, n)) {
            // Place the Queen - Assuming i, j is the right position
            board[i][j] = 1;

            bool nextQueenSuccess = solveNQueen(board, i + 1, n);

            if(nextQueenSuccess)
                return true;
            // Means i, j is not the right position - Assumption is wrong
            board[i][j] = 0; // Backtrack
        }
    }
    // Tried for all position in the current row but couldn't palce a queen

    return false;
}

signed main() {
    int n;
    vector<vector<int>> board(10, vector<int>(10, 0));
    cin >> n;
    solveNQueen(board, 0, n);

}
