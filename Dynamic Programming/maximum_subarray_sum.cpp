#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &num : nums)
        cin >> num;
    
    int mxSum = 0, currSum = 0;

    for(int i = 0; i < n; i++) {
        currSum += nums[i];
        mxSum = max(mxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    cout << mxSum << endl;
}