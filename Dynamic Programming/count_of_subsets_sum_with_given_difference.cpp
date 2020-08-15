#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&nums, int sum) {
    int n = nums.size();
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][sum];
}


signed main() {
    int n,diff;
    cin >> n >> diff;
    vector<int> nums(n);

    for(auto &num : nums) {
        cin >> num;
    }
    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);
    int targetSum = (sum + diff) / 2;
    cout << targetSum << endl;
    cout << solve(nums, targetSum) << endl;

}