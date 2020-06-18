#include<bits/stdc++.h>
using namespace std;
#define int long long

void bubble_sort(vector<int> &v, int n) {
    if(n == 1)
        return;
    for(int j = 0; j < n - 1; j++) {
        if(v[j] > v[j + 1])
            swap(v[j], v[j + 1]);
    }
    bubble_sort(v, n - 1);

}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    bubble_sort(v, n);
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}