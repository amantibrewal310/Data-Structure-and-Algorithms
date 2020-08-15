#include<bits/stdc++.h>
using namespace std;

/*
    !Problem - Connecting Wires

    - There are n white dots and n black dots, equally spaced in a line.
    - You want o connect each white dot with some one black dot, with a minimum total length of wire

    Find the total length of wire needed.

    Inputs-
    White Dots Positions = []
    Black DOts positions = []
*/

signed main() {
    int n;
    cin >> n;
    vector<int> blacks(n);
    vector<int> white(n);

    for(int i = 0; i < n; i++) {
        cin >> blacks[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> white[i];
    }

    sort(blacks.begin(), blacks.end());
    sort(white.begin(), white.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(white[i] - blacks[i]);
    }
    cout << ans << endl;
}