#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int> &v, int low, int high, int x) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return mid;
        else if(x > v[mid])
            return binarySearch(v, mid + 1, high, x);
        else if(x < v[mid])
            return binarySearch(v, low, mid - 1, x);
    }
    return -1;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int x;
    cin >> x;
    cout << binarySearch(v, 0, n - 1, x) + 1 << endl;
}