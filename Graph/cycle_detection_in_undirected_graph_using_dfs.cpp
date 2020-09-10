//?https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycleStart, cycleEnd;

bool dfs(int v, int par) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent node
        if(color[u] == 0) {
            parent[u] = v;
            if(dfs(u, parent[u]))
                return true;
        } else if(color[u] == 1) {
            cycleEnd = v;
            cycleStart = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void findCycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycleStart = -1;

    for(int v = 0; v < n; v++) {
        if(color[v] == 0 and dfs(v, parent[v]));
            break;
    }
    if(cycleStart == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for(int v = cycleEnd; v != cycleStart; v = parent[v]) 
            cycle.push_back(v);
        cycle.push_back(cycleStart);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Found: ";
        for(int v : cycle) {
            cout << v << " ";
        } 
        cout << endl;
    }
}