#include<bits/stdc++.h>
using namespace std;

/*
    # Friends Pairing Problem
    --------------------------
    Given N, friends who want to go to party on bike. Each guy can go as single, or as a couple. Find the numbers of ways in which N friends can go to the party.

    N = 3 
    Ways = 4;
*/

int solve(int n) {
    if(n == 0 or n == 1) {
        return 1;
    } else if(n == 2) {
        return 2;
    }

    return solve(n - 1) + (n - 1) * solve(n - 2);
}

signed main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}