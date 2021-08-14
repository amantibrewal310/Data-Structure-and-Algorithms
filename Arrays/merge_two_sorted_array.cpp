#include <bits/stdc++.h>
using namespace std;

// GAP Method
// TC - N * logN
void merge(vector<int> &arr1, vector<int> &arr2) {
  int n = arr1.size();
  int m = arr2.size();

  int gap = (n + m) / 2;

  while (gap != 0) {
    int i = 0;
    int j = i + gap;

    while (i < n + m and j < n + m) {
      if (i < n and j < n) {
        if (arr1[i] > arr1[j]) {
          swap(arr1[i], arr1[j]);
        }
      } else if (i < n and j >= n) {
        if (arr1[i] > arr2[j - n]) {
          swap(arr1[i], arr2[j - n]);
        }
      } else {
        if (arr2[i - n] > arr2[j - n]) {
          swap(arr2[i - n], arr2[j - n]);
        }
      }
      i++;
      j++;
    }
    if (gap == 1) break;
    gap = gap / 2 + (gap % 2);  // important
  }
}

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);

  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }
  merge(arr1, arr2);

  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int j = 0; j < m; j++) {
    cout << arr2[j] << " ";
  }
  cout << endl;
}