#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack) {
    visited[i] = true;

    for(auto nbr : graph[i]) {
        if(!visited[nbr]) {
            dfs(graph, nbr, visited, stack);
        }
    }
    // function call is complete
    stack.push_back(i);
}
void dfs2(vector<int> graph[], int i, bool *visited) {
    visited[i] = true;

    for(auto nbr : graph[i]) {
        if(!visited[nbr]) {
            dfs2(graph, nbr, visited);
        }
    }
}


void solve(vector<int> graph[], vector<int> rev_graph[], int N) {
    bool visited[N];
    memset(visited, 0, N);

    vector<int> stack;
    // Step - 1 need store the vertices acc to dfs finish time

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            dfs(graph, i, visited, stack);
        }
    }

    // Ordering = Stack
    // Step 2 - reverse

    // Step 3 - Do dfs acc to ordering given in the stack
    memset(visited, 0, N);
    int cnt = 0;
    for(int x = stack.size() - 1; x >= 0; x--) {
        int node = stack[x];
        if(!visited[node]) {
            // There is component starting from this node
            dfs2(rev_graph, node, visited);
            cnt++;
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];
    vector<int> rev_graph[n];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}