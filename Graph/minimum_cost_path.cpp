//?https://www.geeksforgeeks.org/min-cost-path-dp-6/
#include<bits/stdc++.h>
using namespace std;

struct cell {
    int x;
    int y;
    int cost;
};

class cmp {
    public:
        bool operator() (const cell &lhs, const cell &rhs) const{
            return (lhs.cost > rhs.cost);
        }
};

bool isValid(int i, int j, int n, int m) {
    if(i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}

int minCost(vector<vector<int>> &cost) {
    int n = cost.size();
    int m = cost[0].size();

    bool visited[n][m];
    int dp[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = INT_MAX;
            visited[i][j] = false;
        }
    }

    priority_queue<cell, vector<cell>, cmp> pq;

    dp[0][0] = 0;
    pq.push({0, 0, cost[0][0]});

    while(!pq.empty()) {
        cell top = pq.top();
        pq.pop();

        int x = top.x;
        int y = top.y;
        if(visited[x][y]) continue;

        visited[x][y] = true;

        // Examine all the non - visited neighbours
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        for(int i = 0; i < 8; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];

            if(isValid(X, Y, n, m) and visited[X][Y] == false) {
                dp[X][Y] = min(dp[X][Y], dp[x][y] + cost[X][Y]);
                pq.push({X, Y, dp[X][Y]});
            }
        }
    }
    cout << "----------------------" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n - 1][m - 1];
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    cout << minCost(cost) + cost[0][0] << endl;
    
}