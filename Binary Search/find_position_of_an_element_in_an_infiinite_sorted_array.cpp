//?https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int> &v, int low, int high, int x) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return mid;
        else if(v[mid] > x)
            return binarySearch(v, low, mid - 1, x);
        else
            return binarySearch(v, mid + 1, high, x);
    }
    return -1;
}

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int low = 0;
    int high = 1;
    while(x > v[high]) {
        low = high;
        high = high * 2;
    }
    cout << binarySearch(v, low, high, x) << endl;
    
}