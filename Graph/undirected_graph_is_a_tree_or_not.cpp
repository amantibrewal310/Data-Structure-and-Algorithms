#include<bits/stdc++.h>
using namespace std;

bool isTree(vector<vector<int>> adj, int n) {
    bool visited[n];
    int parent[n];

    queue<int> Q;

    for(int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = i;
    }

    int src = 0;
    Q.push(src);
    visited[src] = true;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for(int nbr : adj[node]) {
            if(visited[nbr] == true and parent[node] != nbr) {
                return false;
            } else if(!visited[nbr]) {
                visited[nbr] = true;
                parent[nbr] = node;
                Q.push(nbr);
            }
        }
    }
    return true;
}