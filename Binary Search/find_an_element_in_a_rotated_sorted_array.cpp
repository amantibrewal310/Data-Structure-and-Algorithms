//?https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int search(vector<int> nums, int target) {
    if(nums.size() == 0)
        return -1;
    
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int start = left;
    left = 0;
    right = nums.size() - 1;

    if(target >= nums[start] && target <= nums[right]) {
        left = start;
    } else {
        right = start;
    }

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++)
        cin >> v[i];
    int x;
    cin >> x; 

}