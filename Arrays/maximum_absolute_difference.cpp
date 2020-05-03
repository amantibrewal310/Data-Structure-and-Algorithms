#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxDiff(vector<int> &a) {
    int n = a.size();
    int ans = 0;
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;

    for(int i = 0; i < n; i++) {
        max1 = max(max1, a[i] + i);
        min1 = min(min1, a[i] + i);
        max2 = max(max2, a[i] - i);
        min2 = min(min2, a[i] - i);
    }

    ans = max(max1 - min1, max2 - min2);
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int ans = maxDiff(v);
}