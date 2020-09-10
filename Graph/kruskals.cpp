#include <bits/stdc++.h>
using namespace std;

struct Edges {
    int u;
    int v;
    int weight;
};

bool cmp (Edges a, Edges b) {
    return a.weight < b.weight;
}
vector<Edges> edges;
vector<int> parent;
vector<int> size;

void makeSet(int v) {
    parent[v] = v;
    size[v] = 0;
}

int findSet(int v) {
    if(parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if(a != b) {
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        if(size[a] == size[b])
            size[a]++;
    }
}

int kruskal(vector<Edges> edges, int n) {
    parent.resize(n);
    size.resize(n);

    for(int i = 0; i < n; i++) {
        makeSet(i);
    }
    int cost = 0;
    vector<Edges> result;
    sort(edges.begin(), edges.end(), cmp);
    
    for(Edges e : edges) {
        if(findSet(e.u) != findSet(e.v)) {
            cost += e.weight;
            result.push_back(e);
            unionSet(e.u, e.v);
        }
    }
    return cost;
}

signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        Edges e;
        cin >> e.u >> e.v >> e.weight;
        edges.push_back(e);
    }
    cout << kruskal(edges, n) << endl;
    
}