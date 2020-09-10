#include<bits/stdc++.h>
using namespace std;

/*
    Pairing Problem
    ----------------
    There are N cities numbered from 0 to N - 1. You have to choose 2 cities such that there is no path from first city to second city. You are given information in the form of M pairs (X, Y) i.e there is an undirected road between city X and Y. Find out th number of ways in which cities can be chosen.

    INPUT FORMAT
    -------------
    The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

    Constraints :

    1 <= N <= 10^5
    1 <= M <= 10^5
    0 <= X, Y <= N - 1

*/

int findSet(int i, int parent[]) {
    if(parent[i] == -1)
        return i;
    return parent[i] = findSet(parent[i], parent);
}

void unionSet(int x, int y, int parent[], int rank[]) {
    int s1 = findSet(x, parent);
    int s2 = findSet(y, parent);

    if(s1 != s2) {
        if(rank[s1] < rank[s2]) {
            parent[s2] = s1;
            rank[s2] += rank[s1];
        } else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

int pairing(vector<pair<int, int>> &edgeList, int n) {
    int *parent = new int[n];
    int *rank = new int[n];

    for(int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 1;
    }

    int ans = 0;

    for(auto edge : edgeList) {
        int u = edge.first;
        int v = edge.second;

        int s1 = findSet(u, parent);
        int s2 = findSet(v, parent);

        unionSet(s1, s2, parent, rank);
    }

    // Go to all the nodes
    for(int i = 0; i < n; i++) {
        ans += n - rank[findSet(i, parent)];
    }
    delete [] parent;
    delete [] rank;
    return ans / 2;
    
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edgeList;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }
    cout << pairing(edgeList, n) << endl;
}