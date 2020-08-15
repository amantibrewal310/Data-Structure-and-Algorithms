#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    queue< pair<int, int> > Q;
    bool visited[100007] = {false};
    vector<int> g[100007];
    vector<vector<int>> ans;

    int N, E;
    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int source;
    cin >> source;

    Q.push({source, 0});
    visited[source] = true;
    map<int, int> mp;

    while(!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        int u = p.first;
        int d = p.second;
        // if(d + 1 > ans.size()) {
        //     ans.push_back({u});
        // } else {
        //     ans[d].push_back(u);
        // }
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
    // for(auto v : ans) {
    //     for(auto x : v) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    for(auto p : mp) {
        cout << p.first << "---" << p.second << endl;
    }

}