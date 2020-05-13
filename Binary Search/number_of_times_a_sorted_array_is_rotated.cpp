#include<bits/stdc++.h>
using namespace std;
#define int long long

int countRotations(vector<int> &v, int low, int high) {
    if(high < low)
        return 0;
    if(high == low)
        return low;
    int mid = low + (high - low) / 2;
    if(mid < high && v[mid + 1] < v[mid])
        return mid + 1;
    if(mid > low && v[mid] < v[mid - 1])
        return mid;
    
    if(v[high] > v[mid])
        return countRotations(v, low, mid - 1);
    return countRotations(v, mid + 1, high);

}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << countRotations(v, 0, n - 1) << endl;
}