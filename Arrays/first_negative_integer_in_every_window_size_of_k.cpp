//?https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for(auto &num : nums) {
            cin >> num;
        }
        cin >> k;

        deque<int> Q;

        for(int i = 0; i < k; i++) {
            if(nums[i] < 0) {
                Q.push_back(i);
            }
        }
        vector<int> ans;
        for(int i = k; i < n; i++) {
            if(!Q.empty() and i - k > Q.front()) {
                Q.pop_front();
            }
            if(!Q.empty()) {
                ans.push_back(nums[Q.front()]);
            } else {
                ans.push_back(0);
            }
            if(nums[i] < 0) {
                Q.push_back(i);
            }
        }
        // cout << Q.size() << endl;
        if(!Q.empty() and n - k > Q.front()) {
            Q.pop_front();
        }
        if(!Q.empty()) {
            ans.push_back(nums[Q.front()]);
        } else {
            ans.push_back(0);
        }
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << endl;

    }
}