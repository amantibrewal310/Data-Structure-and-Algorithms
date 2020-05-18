//?https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int firstOccurrence(vector<int> &v, int low, int high, int x) {
    int res = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == x) {
            res = mid;
            high = mid - 1;
        } else if(v[mid] > x) {
           high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int low = 0, high = 1;
    while(v[high] == 0) {
        low = high;
        high = high * 2;
    }
    cout << firstOccurrence(v, low, high, 1) << endl;
    

}