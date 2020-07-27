#include<bits/stdc++.h>
using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &arr, int s) 
{
  // your code goes here
  int n = arr.size();
  int mn1 = INT_MAX;
  int mn2 = INT_MAX;
  int mn3 = INT_MAX;
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        for(int l = 0; l < n; l++) {
          if(i == j or i == k or i == l or j == k or j == l or k == l)
              continue;
          int sum = arr[i] + arr[j] + arr[k] + arr[l];
          if(sum == s and l < mn1 and k < mn2 and j < mn3) {
            mn1 = l;
            mn2 = k;
            mn3 = j;
            // cout << l << endl;

            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            sort(temp.begin(), temp.end());
            ans = temp;
            
          }
          
        }
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for(auto &x : arr) {
      cin >> x;
  }
  int s;
  cin >> s;
  vector<int> ans = findArrayQuadruplet(arr, s);
  for(auto i : ans)
    cout << i << " ";
   cout << endl;
}