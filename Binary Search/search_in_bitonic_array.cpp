//?https://www.geeksforgeeks.org/find-element-bitonic-array/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int asscBinarySearch(vector<int> &v, int low, int high, int x) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return x;
        else if(v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int descBinarySearch(vector<int> &v, int low, int high, int x) {
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return x;
        else if(v[mid] > x)
            low = mid - 1;
        else
            high = mid + 1;
    }
    return -1;
}

int findPeak(vector<int> &v) {
    int n = v.size();
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(v[mid + 1] > v[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

signed main() {
    int n, key;
    cin >> n >> key;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int pivot = findPeak(v);
    int x = asscBinarySearch(v, 0, pivot, key);
    int y = descBinarySearch(v, pivot + 1, n - 1, key);
    if(x == -1 and y == -1)
        cout << -1 << endl;
    else if(x == -1 and y != -1)
        cout << y << endl;
    else
        cout << x << endl;
}