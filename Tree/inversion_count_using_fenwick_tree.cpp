#include<bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for(size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int getInversionCnt(vector<int> &v) {
    int n = v.size();

    int invCnt = 0;
    int mx = *max_element(v.begin(), v.end());

    FenwickTree* bit = new FenwickTree(mx);
    
    for(int i = n - 1; i >= 0; i--) {
        invCnt += bit->sum(v[i] - 2);
        bit->add(v[i] - 1, 1);
    }

    return invCnt;


}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << getInversionCnt(v) << endl;
}