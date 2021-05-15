#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int i, int j, int steps) {
    if (i >= 0 and i < n and j >= 0 and j < m) {
        if (g[i][j] <= steps) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

bool isEscape(int i, int j, int steps) {
    if (isValid(i, j, steps)) {
        if (i == 0 or i == n - 1 or j == 0 or j == m - 1)
            return true;
    }
    return false;
}

void preprocess(string mat[]) {
    queue<vector<int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'M') {
                Q.push({i, j, 0});
            }
        }
    }

    while (!Q.empty()) {
        vector<int> v = Q.front();
        int x = v[0];
        int y = v[1];
        int steps = v[2];
        Q.pop();
        steps++;

        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (isValid(X, Y, steps) and mat[X][Y] != '#') {
                Q.push({X, Y, steps});
                g[X][Y] = steps;
            }
        }
    }
}

void solve(string mat[]) {
    pair<int, int> src, dest;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'A') {
                src = {i, j};
                break;
            }
        }
    }
    map<pair<int, int>, pair<pair<int, int>, char>> parent;
    bool flag = false;
    queue<vector<int>> Q;
    Q.push({src.first, src.second, 0});

    while (!Q.empty()) {
        vector<int> v = Q.front();
        int x = v[0];
        int y = v[1];
        int steps = v[2];
        steps++;
        Q.pop();
        if (isEscape(x, y, steps - 1) and mat[x][y] != '#') {
            dest = {x, y};
            flag = true;
            break;
        }
        string dir = "DRUL";
        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (isEscape(X, Y, steps) and mat[X][Y] != '#') {
                dest = {X, Y};
                parent[{X, Y}] = {{x, y}, dir[i]};
                flag = true;
                break;
            }
            if (isValid(X, Y, steps) and mat[X][Y] != '#') {
                parent[{X, Y}] = {{x, y}, dir[i]};
                Q.push({X, Y, steps});
                g[X][Y] = steps;
            }
        }
        if (flag) {
            break;
        }
    }

    if (flag) {
        string ans = "";
        while (dest != src) {
            ans += parent[dest].second;
            dest = parent[dest].first;
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    cin >> n >> m;
    string mat[n];
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    g.assign(n, vector<int>(m, INT_MAX));
    preprocess(mat);
    solve(mat);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}