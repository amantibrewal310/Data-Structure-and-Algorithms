//?https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> board(31, 0);
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            board[a] = b - a;
        }
        vector<int> g[31];
        bool visited[31] = {false};
        for(int i = 1; i < 30; i++) {
            for(int dice = 1; dice <= 6; dice++) {
                int j = i + dice;
                j += board[j];

                if(j <= 30) {
                    g[i].push_back(j);
                }
            }
        }
        g[30].push_back(30);

        queue<pair<int, int>> Q;
        Q.push({1, 0});
        visited[1] = true;
        map<int, int> mp;

        while(!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int u = p.first;
            int d = p.second;
            mp[u] = d;

            int size = g[u].size();
            for(int i = 0; i < size; i++) {
                int v = g[u][i];

                if(visited[v] == false) {
                    Q.push({v, d + 1});
                    visited[v] = true;
                }
            }
        }
        cout << mp[30] << endl;

    }
}