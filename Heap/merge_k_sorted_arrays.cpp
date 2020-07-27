#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > customPair;

vector<int> mergeKSortedArrays(vector<vector<int>> arr) {
    vector<int> res;
    priority_queue<customPair, vector<customPair>, greater<customPair> > pq; // min heap;

    // insert the 0th element of every in the pq;
    for(int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], {i, 0}});
    }

    // remove the elements one by one from the min heap and add to result vector

    while(!pq.empty()) {
        customPair curr = pq.top();
        pq.pop();
        int element = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        res.push_back(element);
        
        // you need to pusht the next elemtn of current element x, y + 1 to min heap

        if(y + 1 < arr[x].size()) {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return res;

}

signed main() {
    vector<vector<int> > arr {
                                {2, 6, 12, 15},
                                {1, 3, 14, 20},
                                {3, 5, 8, 10}
                            };
    vector<int> res = mergeKSortedArrays(arr);
    for(auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}