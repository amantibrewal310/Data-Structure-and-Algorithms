#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s = "39,45,65,75";

  stringstream ss(s);
  string tmp;
  vector<int> nums;
  while (getline(ss, tmp, ',')) {
    // cout << tmp << endl;
    int num = stoi(tmp);
    nums.push_back(num);
  }
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}