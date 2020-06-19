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

void bubble_sort_recursive(vector<int> &v, int j, int n) {
    // base case
    if(n == 1)
        return;
    
    if(j == n - 1) {
        //single pass of current array has been done
        return bubble_sort_recursive(v, 0, n - 1);
    }
    if(v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
    }
    bubble_sort_recursive(v, j + 1, n);
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