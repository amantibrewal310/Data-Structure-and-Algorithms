#include<bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b) {
        if(minHeap)
            return a < b;
        else {
            return a > b;
        }
    }

    void heapify(int idx) {
        int leftChild = 2 * idx;
        int rightChild = 2 * idx + 1;
        
        int minIdx = idx;
        int last = v.size() - 1;
        if(leftChild <= last and compare(v[leftChild], v[idx]) )
            minIdx = leftChild;
        
        if(rightChild <= last and compare(v[rightChild], v[minIdx]))
            minIdx = rightChild;
        if(minIdx != idx) {
            swap(v[idx], v[minIdx]);
            heapify(minIdx);
        }

    }

    public:
        Heap(int default_size = 10, bool type = true) {
            v.reserve(default_size);
            v.push_back(-1);
            minHeap = type;
        }

        void push(int d) {
            v.push_back(d);
            int idx = v.size() - 1;
            int parent = idx / 2;
            
            // keep pushing to the top till you reach a root node or stop midway because current element is already greater than parent
            
            while(idx > 1 and compare(v[idx], v[parent]) ) {
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }

        int top() {
            return v[1];
        }

        void pop() {
            int last_idx = v.size() - 1;
            swap(v[1], v[last_idx]);
            v.pop_back();
            heapify(1);
        }

        bool empty() {
            return v.size() == 1;
        }
};

signed main() {
    Heap h(10, false);
    int n; 

    cin >> n;
    for(int i = 0; i < n; i++) {
        int no;
        cin >> no;
        h.push(no);
    }

    while(!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
}