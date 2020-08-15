#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> solve(vector<int> &nums, int sum) {
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
    vector<int> ans;
    for(int i = 0; i <= sum / 2; i++) {
        if(dp[n][i])
            ans.push_back(i);
    }
    return ans;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &num : nums) {
            cin >> num;
        }
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        // memset(dp, -1, sizeof(dp));
        vector<int> possibleSum = solve(nums, sum);

        int mn = INT_MAX;

        for(int i = 0; i < possibleSum.size(); i++) {
            mn = min(mn, sum - 2 * possibleSum[i]);
        }
        cout << mn << endl;
    }
}