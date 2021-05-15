#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m) {
    if (i >= 0 and i < n and j >= 0 and j < m) {
        return true;
    }
    return false;
}

signed main() {
    int n, m;
    cin >> n >> m;
    string mat[n];
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    queue<pair<int, int>> Q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int, int> src, des;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'A') {
                Q.push({i, j});
                visited[i][j] = true;
                src = {i, j};
            } else if (mat[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }
    bool flag = false;
    map<pair<int, int>, pair<pair<int, int>, char>> parent;
    while (Q.size() > 0) {
        auto p = Q.front();
        Q.pop();
        int x = p.first;
        int y = p.second;

        if (mat[x][y] == 'B') {
            flag = true;
            des = {x, y};
            break;
        }

        int dx[] = {+1, 0, -1, 0};
        int dy[] = {0, +1, 0, -1};
        string dir = "DRUL";

        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (isValid(X, Y, n, m) and !visited[X][Y]) {
                parent[{X, Y}] = {{x, y}, dir[i]};
                Q.push({X, Y});
                visited[X][Y] = true;
            }
        }
    }

    if (flag) {
        cout << "YES" << endl;
        string ans = "";
        while (true) {
            ans += parent[des].second;
            des = parent[des].first;
            if (des.first == src.first and des.second == src.second) {
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
}