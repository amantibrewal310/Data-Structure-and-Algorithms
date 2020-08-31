#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

signed main() {
    int nodes, edges;
    cin >> nodes >> edges;
    adj.assign(nodes + 1, vector<int>());

    for(int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> inDegree(nodes + 1, 0);

    for(auto v : adj) {
        for(auto u : v) {
            inDegree[u]++;
        }
    }
    queue<int> Q;
    
    for(int i = 0; i < nodes; i++) {
        if(inDegree[i] == 0)
            Q.push(i);
    }
    vector<int> ans;
    while(!Q.empty()) {
        int node = Q.front();
        ans.push_back(node);
        Q.pop();
        
        for(auto nbr : adj[node]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0)
                Q.push(nbr);
        }
    }
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}