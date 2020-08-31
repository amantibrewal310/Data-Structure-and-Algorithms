#include<bits/stdc++.h>
using namespace std;
const int N = 8;

int solveKnightMove(int board[N][N], int move_no, int currRow, int currCol) {

    int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    for(int curDir = 0; curDir < 8; curDir++) {
        int nextRow = currRow + rowDir[curDir];
    }
}

signed main() {
    int board[N][N] = {0};
    int n;
    cin >> n;
    int move_no = 1;

}