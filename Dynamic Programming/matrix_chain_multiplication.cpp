//?https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int i, int j) {
    if(i >= j)
        return 0;
    
    int ans = INT_MAX;

    for(int k = i; k <= j - 1; k++) {
        int temp = solve(nums, i, k) + solve(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j];

        ans = min(ans, temp);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int &num : nums)
        cin >> num;
}