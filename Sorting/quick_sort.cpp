#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for(int j = l; j <= r - 1; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int> &a, int l, int r) {

    if(l >= r) 
        return;
    
    int p = partition(a, l, r);

    //left part
    quickSort(a, l, p - 1);
    //right part
    quickSort(a, p + 1, r);
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    quickSort(a, 0, n - 1);
    for(auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}