#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n);
    int l = 0, r = n - 1, k;
    cin >> k;

    while(l < r) {
        int currSum = a[l] + a[r];
        if(currSum > k)
            r--;
        else if(currSum < k)
            l++;
        else {
            cout << a[l] << " " << a[r] << endl;
            l++;
            r--;
        }
    }
}