#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement - Given N ropes of different sizes, we have join the ropes together.
    --------------------------------------
    The cost of joining 2 ropes of different sizes A and B is (A + B). Fidn the minimum cost to join all the ropes together.

*/

int join_ropes(vector<int> &ropes) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(auto i : ropes) {
        minHeap.push(i);
    }
    int ans = 0, cost = 0;
    while(minHeap.size() > 1) {
        int A = minHeap.top();
        minHeap.pop();
        int B = minHeap.top();
        minHeap.pop();
        cost += A + B;
        minHeap.push(A + B);
    }
    return cost;

}

signed main() {
    vector<int> ropes{4, 3, 2, 6};

    cout << join_ropes(ropes) << endl;
}