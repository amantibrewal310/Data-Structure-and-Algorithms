//?https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/description/

#include<bits/stdc++.h>
using namespace std;


int prim_mst(vector<pair<int, int>> adj[], int n) {

    //most important stuff
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    // another array
    // visited array that denotes wheter a node has been included in MST or NOT

    bool visited[n + 1] = {false};
    int ans = 0;

    // Begin
    pq.push({0, 1}); // ({W, NODE})

    while(!pq.empty()) {
        // Pick out the edge with min weight
        auto best = pq.top();
        pq.pop();
        int w = best.first;
        int u = best.second;

        if(visited[u] == true) {
            // Discard the edge, and continue;
            continue;
        }

        // Otherwise tak the current edge

        ans += w;
        visited[u] = 1;

        // add the new edges in the queue

        for(auto p : adj[u]) {
            int v = p.first;
            if(visited[v] == false) {
                pq.push({p.second, v});
            }
        }
    }
    return ans;

}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << prim_mst(adj, n) << endl;
}