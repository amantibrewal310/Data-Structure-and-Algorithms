/* Inversion Count Problem

    find pairs such that a[i] > a[j] for i < j
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int merge(vector<int> &a, int l, int r) {
    int mid = l + (r - l) / 2;
    int i = l;
    int j = (mid + 1);

    int cnt = 0; // cross inversions
    vector<int> temp;
    while(i <= mid and j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
            cnt += mid - i + 1;
        }
    }
    while(i <= mid) {
        temp.push_back(a[i++]);
    }
    while(j <= r) {
        temp.push_back(a[j++]);
    }

    int k = 0;
    for(int i = l; i <= r; i++) {
        a[i] = temp[k++];
    }
    return cnt;
}

int countInversion(vector<int> &a, int l, int r) {
    if(l == r)
        return 0;
    
    int mid = l + (r - l) / 2;
    int x = countInversion(a, l, mid);
    int y = countInversion(a, mid + 1, r);
    int z = merge(a, l, r); // cross inversions

    return x + y + z;
}


signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << countInversion(a, 0, n - 1) << endl;
} 