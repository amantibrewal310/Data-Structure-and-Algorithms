#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> puzzleList;
queue<int> q;
int b[9];

void compute(int x, int y, int curr, int distance) {
    int first = (curr / b[x]) % 10;
    int second = (curr / b[y]) % 10;
    // swap the two numbers
    curr += (second - first) * b[x] + (first - second) * b[y];
    if (puzzleList.find(curr) == puzzleList.end()) {
        puzzleList[curr] = distance + 1;
        q.push(curr);
    }
}

void solve(int x) {
    b[8] = 1;
    for (int i = 7; i >= 0; i--) {
        b[i] = b[i + 1] * 10;
    }

    int puzzle = 123456789;
    puzzleList[puzzle] = 0;
    q.push(puzzle);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == x) {
            cout << puzzleList[x] << endl;
            return;
        }
        int prevDist = puzzleList[curr];

        // apply the bfs practical logic
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i < 2) {
                    compute(3 * i + j, 3 * (i + 1) + j, curr, prevDist);
                }
                if (j < 2) {
                    compute(3 * i + j, 3 * i + 1 + j, curr, prevDist);
                }
            }
        }
    }
    if (puzzleList.find(x) != puzzleList.end()) {
        cout << puzzleList[x] << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    int t, puzzle, x;
    // preprocess();
    // cin >> t;
    t = 1;
    while (t--) {
        puzzle = 0;
        for (int i = 0; i < 9; i++) {
            cin >> x;
            puzzle = puzzle * 10 + x;
        }
        solve(puzzle);
    }
}