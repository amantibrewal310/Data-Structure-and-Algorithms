#include <bits/stdc++.h>
using namespace std;
#define maxN 1005

int dp[maxN];

int go(int arr[], int n) {
  if (n == 0) return 0;
  if (n == 1) return arr[0];
  if (n == 2) return arr[0] + arr[1];

  if (dp[n] != -1) return dp[n];

  int ans = 0;

  // we dont pick current element
  ans = go(arr, n - 1);
  cout << ans << endl;
  // we pick only one consecutive element
  ans = max(ans, arr[n - 1] + go(arr, n - 2));
  // if we pick two consecutive element
  ans = max(ans, arr[n - 1] + arr[n - 2] + go(arr, n - 3));

  return dp[n] = ans;
}
int main() {
  // your code goes here
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  memset(dp, -1, sizeof dp);

  cout << "sum = " << go(arr, n) << endl;

  return 0;
}