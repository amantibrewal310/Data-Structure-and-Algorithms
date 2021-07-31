/****
 *     @Just Another Source code by: ankit.sangwan1999
 *    @created on: 11 Jul 2020
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)  //;cout.tie(NULL)
#define ll long long
const int mod = 1e9 + 7;
const long double pie = 3.14159265358979323846;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, ll> ma;  // orderd_map using pb_ds

int ranks[50];
bool fun(int mid, int l, int p) {
  int pratas = 0;
  for (int i = 0; i < l; i++) {
    // pratas += bin(2*mid/ranks[i]);
    int a = 2 * mid / ranks[i];
    int biggerRoot = ((int)sqrt(4 * a + 1) - 1) / 2;
    pratas += biggerRoot >= 0 ? biggerRoot : 0;
  }
  return pratas >= p;
}

void solve() {
  int p;
  cin >> p;
  int l;
  cin >> l;
  for (int i = 0; i < l; i++) {
    cin >> ranks[i];
  }

  int low = 0;
  int high = 4 * p * (p + 1);
  int ans = 0;
  while (low <= high) {
    int mid = low + (high - low) /
                        2;  // Check if p pratas can be prepared in mid Time.

    // Iterative
    int pratas = 0;
    bool did = 0;
    for (int i = 0; i < l; i++) {
      // pratas += bin(2*mid/ranks[i]);
      int a = 2 * mid / ranks[i];
      int biggerRoot = ((int)sqrt(4 * a + 1) - 1) / 2;
      pratas += biggerRoot >= 0 ? biggerRoot : 0;

      if (pratas >= p) {
        high = mid - 1;
        ans = mid;
        did = 1;
        break;
      }
    }

    if (did == 0) {
      low = mid + 1;
    }
  }

  cout << ans << endl;
}

signed main() {
  fastio;
  int t = 1;
  cin >> t;

  while (--t >= 0) {
    solve();
  }

  return 0;
}