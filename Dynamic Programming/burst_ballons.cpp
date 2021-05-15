#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int i, int j) {
    if(i + 1 == j) return 0;

    int ans = 0;

    for(int k = i + 1; k < j; k++) {
        int tmp = nums[i] * nums[k] * nums[j];
        tmp += solve(nums, i, k);
        tmp += solve(nums, k, j);
        ans = max(ans, tmp);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n + 2);
    nums[0] = nums[n + 1] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    cout << solve(nums, 0, n - 1) << endl;
    

}