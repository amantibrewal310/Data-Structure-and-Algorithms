//?https://leetcode.com/problems/find-peak-element/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int findPeakElement(vector<int>& nums) {
    int n = nums.size(), low = 0, high = n - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(mid > 0 and mid < n - 1) {
            if(nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1])
                return mid;
            else if(nums[mid + 1] > nums[mid] )
                low = mid + 1;
            else if(nums[mid - 1] > nums[mid])
                high = mid - 1;
        } else if(mid == 0) {
            if(nums[0] > nums[1])
                return 0;
            else
                return 1;
        } else if(mid == n - 1) {
            if(nums[n - 1] > nums[n - 2])
                return n - 1;
            else
                return n -2;
        }
    }
    return low;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << findPeakElement(v) << endl;
    
    
}