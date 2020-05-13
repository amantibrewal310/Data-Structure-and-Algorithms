//?https://www.geeksforgeeks.org/search-almost-sorted-array/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int search(vector<int> &v, int low, int high, int x) {
    if(low > high)
        return -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x)
            return mid;
        else if(mid - 1 >= low && v[mid - 1] == x)
            return mid - 1;
        else if(mid + 1 <= high && v[mid + 1] == x)
            return mid + 1;
        else if(v[mid] > x) {
            high = mid - 2;
        } else {
            low = mid + 2;
        }
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
    cout << search(v, 0, n - 1, x) << endl;
}