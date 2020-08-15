//?https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[105][10005];

int solve(vector<int> &nums, int i, int sum) {
    if(sum == 0)
        return 1;
    if(i >= nums.size())
        return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    if(nums[i] <= sum) {
        return dp[i][sum] = solve(nums, i + 1, sum - nums[i]) or solve(nums, i + 1, sum);
    }
    return dp[i][sum] = solve(nums, i + 1, sum);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &num : nums)
            cin >> num;
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2) {
            cout << "NO" << endl;
        } else {
            memset(dp, -1, sizeof(dp));
            if(solve(nums, 0, sum / 2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

}