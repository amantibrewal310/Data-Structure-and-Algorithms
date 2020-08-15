#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[105][1005];

int solve(vector<int> &nums, int i, int sum) {
    if(sum == 0)
        return 1;
    
    if(i >= nums.size())
        return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    if(nums[i] <= sum)
        return dp[i][sum] = solve(nums, i + 1, sum - nums[i]) + solve(nums, i + 1, sum);
    
    return dp[i][sum] = solve(nums, i + 1, sum);
}

signed main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);

    for(auto &num : nums)
        cin >> num;
    
    memset(dp, -1, sizeof(dp));

    cout << solve(nums, 0, sum) << endl;
}