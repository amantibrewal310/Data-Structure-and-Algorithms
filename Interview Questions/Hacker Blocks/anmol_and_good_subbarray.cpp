//?https://hack.codingblocks.com/app/contests/1783/1739/problem
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &num : nums) {
        cin >> num;
    }
    vector<int> prefix(n);
    prefix[0] = nums[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    int cnt = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        if(prefix[i] == 0)
            cnt++;
        if(mp.find(prefix[i]) != mp.end()) {
            cnt += mp[prefix[i]];
        }
        mp[prefix[i]]++;
    }
    // cnt += mp[0];
    int total = n * (n + 1) / 2;
    int ans = total - cnt;
    cout << ans << endl;
}