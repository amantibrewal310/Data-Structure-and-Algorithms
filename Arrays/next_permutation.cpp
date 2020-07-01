#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int i, j, small, big;
    int n = A.size();
    for(i = n - 1; i > 0; i--) {
        if(A[i] > A[i - 1])
            break;
    }
    if(i == 0) {
        sort(A.begin(), A.end());
        return A;
    }
    small = i - 1;
    big = i;
    int t = big;
    for(i = n - 1; i > big; i--) {
        if(A[i] > A[small] and A[i] < A[t])
            t = i;
    }
    swap(A[small], A[t]);
    small++;
    sort(A.begin() + small, A.end());
    return A;
} 

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans = nextPermutation(v);
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    
}