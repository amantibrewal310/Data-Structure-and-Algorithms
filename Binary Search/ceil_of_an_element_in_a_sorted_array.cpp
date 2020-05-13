//?https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int ceilSearch(vector<int> &v, int low, int high, int x) {
    int res = -1;
    if(low > high)  
        return -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return mid;
        else if(v[mid] > x) {
            res = mid;
            high = mid - 1;
        }
        else if(v[mid] < x)
            low = mid + 1;
    }
    return res;
}

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << ceilSearch(v, 0, n - 1, x) << endl;
    
}