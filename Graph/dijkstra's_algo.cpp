#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

vector<pair<int, int>> g[SIZE];
// initialize with INF distance
vector<int> dist(SIZE, INT_MAX); 
vector<int> vis(SIZE);

// using priority queue
void dijkstraUsingPQ() {
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

// multiset do the job as a min-priority queue 
void dijkstraUsingMultiset() {
    dist[0] = 0;
    multiset<pair<int, int>> s;
    // insert the source node with distance = 0
    s.insert({0, 0});
    
    while(!s.empty()) {
        int u = s.begin()->second;
        s.erase(*s.begin());

        // vis array is only for further optimization 
        // since there can be more than one pairs of {w, vertex}, in the multiset
        // we are only concerned with the one with min w 
        // all other would be aoutomatically be ignored by condition put below 
        if(vis[u] == true) {
            continue;
        }
        vis[u] = true;

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
}

// using a set, dont need visited array, since every vertex has single {w, vertex} pair 
void dijkstraUsingSet() {
    set<pair<int, int>> s;
    dist[0] = 0;
    s.insert({0, 0});

    while(!s.empty()) {
        int u = s.begin()->second;
        s.erase(*s.begin());

        for(auto pr: g[u]) {
            int w = pr.first;
            int v = pr.second;
            
            if(dist[u] + w < dist[v]) {
                // means v is in the set already
                if(dist[v] != INT_MAX) {
                    // erase it from the set, update with lower weight later
                    s.erase(s.find({dist[v], v}));
                }    
                dist[v] = dist[u] + w;
                s.insert({dist[v], v}); 
            }
        }
    }
}
