#include<bits/stdc++.h>
using namespace std;
#define int long long

int nextAlphabetical(char v[], int low, int high, char c) {
    // cout << hello << endl;
    if(low > high)
        return -1;
    int res = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(v[mid] == c) {
            low = mid + 1;
        } else if(v[mid] > c) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    return res;
}

signed main() {
    int n;
    cin >> n;
    char s[n];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    char c;
    cin >> c;
    int ans = nextAlphabetical(s, 0, n - 1, c);
    if(ans != -1)
        cout << s[ans] << endl;
    else
        cout << ans << endl;
}