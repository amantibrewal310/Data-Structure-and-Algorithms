#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    # PLACE THE TILES
    -----------------
    Given a wall of size of 4 x N, and titles of size (1, 4) and (4, 1)
    In how many ways you can build the wall?

*/

int placeTiles(int n) {
    if(n <= 3)
        return 1;
    return placeTiles(n - 1) + placeTiles(n - 4);
}

signed main() {
    int n;
    cin >> n;
    cout << placeTiles(n) << endl;
    
}