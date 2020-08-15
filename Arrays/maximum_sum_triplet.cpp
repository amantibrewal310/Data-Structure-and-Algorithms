#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> &nums) {
    int n = nums.size();
    vector<int> maxSuffix(n, 0);
    maxSuffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxSuffix[i] = max(maxSuffix[i + 1], nums[i]);
    }
    set<int> s;
    s.insert(INT_MIN);
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (maxSuffix[i + 1] > nums[i]) {
            auto it = s.lower_bound(nums[i]);
            it--;
            int sum = *it + nums[i] + maxSuffix[i + 1];
            ans = max(ans, sum);
        }
        s.insert(nums[i]);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &num : nums) {
        cin >> num;
    }
    cout << solve(nums) << endl;
}