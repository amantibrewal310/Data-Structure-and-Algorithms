#include <bits/stdc++.h>
using namespace std;
#define int long long

int getBestCandidates(map<int, int> &candidates, int num) {
    auto it = candidates.lower_bound(num);
    if (it == candidates.begin()) return 0;
    it--;
    return it->second;
}

void insert(map<int, int> &candidates, int num, int adv) {
    // if (candidates[num] >= adv) {
    //     return;
    // }
    candidates[num] = adv;
    auto it = candidates.find(num);
    it++;
    while (it != candidates.end() and it->second <= adv) {
        auto tmp = it;
        it++;
        candidates.erase(tmp);
    }
}

int solve(vector<int> &nums) {
    int n = nums.size();

    int dp[n];
    map<int, int> candidates;

    dp[0] = 1;
    candidates[nums[0]] = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = 1 + getBestCandidates(candidates, nums[i]);
        insert(candidates, nums[i], dp[i]);
    }

    return *max_element(dp, dp + n);
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &num : nums) {
        cin >> num;
    }
    cout << solve(nums) << endl;
}