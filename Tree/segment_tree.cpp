#include<bits/stdc++.h>
using namespace std;

struct segmentTree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = 1;
        while(size < n)
            size *= 2;
        sums.assign(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {

    }
    void set(int i, int v) {

    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    
    segmentTree st;
    st.init(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.set(i, x);
    }
}