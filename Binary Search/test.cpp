#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
} _;

vector<ll> subset_sum(vector<ll>& a) {
  ll n = a.size();
  vector<ll> res;
  for (ll i = 0; i < (1 << n); i++) {
    ll sum = 0;
    for (ll j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum += a[j];
      }
    }
    res.push_back(sum);
  }

  return res;
}

int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> left(n / 2), right(n - n / 2);

  for (int i = 0; i < n / 2; i++) cin >> left[i];
  for (int i = 0; i < n - n / 2; i++) cin >> right[i];

  vector<ll> left_sum = subset_sum(left);
  vector<ll> right_sum = subset_sum(right);

  ll res = 0;
  map<ll, ll> mp;
  for (auto i : right_sum) mp[i]++;

  for (ll i = 0; i < left_sum.size(); i++) res += mp[t - left_sum[i]];

  cout << res;
  return 0;
}