#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> board(8, vector<int>(8, 0));
int dx[] = {+2, +2, +1, -1, +1, -1, -2, -2};
int dy[] = {-1, +1, +2, +2, -2, -2, +1, -1};

bool isValid(int x, int y) {
    if (x >= 0 and x < 8 and y >= 0 and y < 8) return true;
    return false;
}

int getDegree(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (isValid(X, Y) and board[X][Y] == 0) {
            cnt++;
        }
    }
    return cnt;
}

bool solve(int x, int y, int moves) {
    if (board[x][y]) {
        return false;
    }

    if (moves == 64) {
        board[x][y] = moves;
        return true;
    }

    board[x][y] = moves;

    vector<pair<int, pair<int, int>>> v;

    for (int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (isValid(X, Y) and board[X][Y] == 0) {
            int degree = getDegree(X, Y);
            v.push_back({degree, {X, Y}});
        }
    }

    sort(v.begin(), v.end());

    for (auto p : v) {
        int degree = p.first;

        // if (degree == 0) continue;

        int X = p.second.first;
        int Y = p.second.second;

        bool isSuccess = solve(X, Y, moves + 1);
        if (isSuccess) {
            return true;
        }
    }

    board[x][y] = 0;

    return false;
}

signed main() {
    int x, y;
    cin >> y >> x;
    // board[x - 1][y - 1] = 1;
    bool ans = solve(x - 1, y - 1, 1);
    if (ans) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}