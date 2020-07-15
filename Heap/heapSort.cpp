#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for(auto i : v) 
        cout << i << " ";
    cout << endl;
}

bool cmp(int a, int b) {
    return a > b;
}

void heapify(vector<int> &v, int idx, int size) {
    int maxIdx = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;
    // cout << v[leftChild] << " " << v[rightChild] << endl;

    int lastIdx = size - 1;

    if(leftChild <= lastIdx and cmp(v[leftChild], v[maxIdx]))
        maxIdx = leftChild;
    if(rightChild <= lastIdx and cmp(v[rightChild], v[maxIdx]))
        maxIdx = rightChild;
    // cout << maxIdx << endl;
    
    if(maxIdx != idx) {
        swap(v[maxIdx], v[idx]);
        heapify(v, maxIdx, size);
    }
}

void buildHeap(vector<int> &v) {
    int n = v.size()/ 2;

    for(int i = n - 1; i >= 0; i--) {
        heapify(v, i, v.size());
    }
}

void heapSort(vector<int> &v) {

    buildHeap(v);
    int n = v.size();

    for(int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

signed main() {
    vector<int> v;
    // v.push_back(-1);

    int n;
    cin >> n;

    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    heapSort(v);
    print(v);
}