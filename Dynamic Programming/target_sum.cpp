//?https://leetcode.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int m) {
    int n = nums.size();
    

    int dp[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << m << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

signed main() {
    int n, targetSum;
    cin >> n >> targetSum;
    vector<int> nums(n);
    for(auto &num : nums)
        cin >> num;
    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), 0);
    int m = (targetSum + sum) / 2;

    cout << solve(nums, m) << endl;
    
}