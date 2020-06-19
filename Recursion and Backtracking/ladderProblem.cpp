#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    Number of ways we can reach to the top of the ladder
    by taking at max k steps
*/

int f(int n, int k) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans += f(n - i, k);
    }
    return ans;
} 

signed main() {
    int n, k;
    cin >> n; // no. of staircase
    cin >> k; // max step allowed
    cout << f(n, k) << endl;

}