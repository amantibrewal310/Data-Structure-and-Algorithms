#include<bits/stdc++.h>
using namespace std;
#define int long long

void merge(vector<int> &a, int l, int r) {
    int mid = l + (r - l) / 2;
    int i = l;
    int j = mid + 1;
    // int k = r;

    vector<int> temp;
    while(i <= mid and j <= r) {
        if(a[i] < a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while(j <= r) {
        temp.push_back(a[j]);
        j++;
    }
    int k = 0;
    for(int i = l; i <=r; i++) {
        a[i] = temp[k++];
    }
}

void merge_sort(vector<int> &a, int l, int r) {
    if(l == r)
        return;
    
    int mid = l + (r - l) / 2;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    merge(a, l, r);

}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for(auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}