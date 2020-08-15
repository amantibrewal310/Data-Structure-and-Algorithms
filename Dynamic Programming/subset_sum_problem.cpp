//?https://www.interviewbit.com/problems/subset-sum-problem/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[105][100005];

int solve(vector<int> &nums, int i, int sum) {
    if(sum == 0)
        return 1;
    if(i >= nums.size())
        return 0;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    if(nums[i] <= sum) {
        return dp[i][sum] = max(solve(nums, i + 1, sum - nums[i]), solve(nums, i + 1, sum));
    }
    return dp[i][sum] = solve(nums, i + 1, sum);
}

// Top Down 
int solveTD(vector<int> &nums, int sum) {
    int n = nums.size();
    int dp[n + 1][sum + 1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            
            if(i == 0) {
                dp[i][j] = 0;
            }
            if(j == 0) {
                dp[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, sum;
        cin >> n >> sum;
        vector<int> nums(n);
        for(auto &num : nums) {
            cin >> num;
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(nums, 0, sum) << endl;
        cout << solveTD(nums, sum) << endl;
        
    }
}