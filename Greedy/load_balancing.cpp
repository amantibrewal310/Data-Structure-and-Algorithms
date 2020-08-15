#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    while(1) {
        int n;
        cin >> n;
        if(n == -1)
            break;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        if(sum % n != 0) {
            cout << -1 << endl;
        } else {
            int load = sum / n;
            int current = 0;
            for(int i = 0; i < n - 1; i++) {
                int diff = a[i] - load;
                a[i + 1] += diff;
                current = max(current, abs(diff));
            }
            cout << current << endl;
        }
    }
    
}