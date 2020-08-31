#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency List
int n;                   // Number of Vertices
int m;                   //Number of Edges
vector<bool> visited;

void dfs(int v)
{
    visited[v] = true;
    cout << v << "->";
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
}
signed main()
{

    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        // Undirected Graph
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
}