#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

// O(N * LogN)
void buildHeap(vector<int> &v) {

    for(int i = 1; i < v.size(); i++) {
        int idx = i;
        int parent = (i - 1) / 2;

        while(idx > 0 and v[idx] > v[parent]) {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

// O(N)
bool compare(int a, int b)
{
    return a > b;
}

void heapify(vector<int> &v, int idx) {

    int leftChild = 2 * idx;
    int rightChild = 2 * idx + 1;

    int minIdx = idx;
    int lastIdx = v.size() - 1;

    if(leftChild <= lastIdx and compare(v[leftChild], v[idx]) ) {
        minIdx = leftChild;
    }
    if(rightChild <= lastIdx and compare(v[rightChild], v[minIdx])) {
        minIdx = rightChild;
    }

    if(minIdx != idx) {
        swap(v[idx], v[minIdx]);
        heapify(v, minIdx);
    }
}


void buildHeap1(vector<int> &v) {
    int n = (v.size() - 1) / 2;

    for(int i = n; i >= 1; i--) {
        heapify(v, i);
    }
}

signed main() {
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    buildHeap1(v);
    print(v);
}