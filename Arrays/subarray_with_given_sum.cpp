//?https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, sum;
        cin >> n >> sum;
        
        vector<int> nums(n);
        for(int &num : nums)
            cin >> num;
        
        int left = 0, right = 0;
        bool flag = 0;
        int currentSum = 0;        
        while(right <= n and currentSum != sum) {
            if(currentSum < sum) {
                currentSum += nums[right];
                right++;
            } else if(currentSum > sum) {
                currentSum -= nums[left];
                left++;
            }
        }
        
        if(currentSum == sum) {
            cout << left + 1 << " " << right << endl;
        } else {
            cout << -1 << endl;
        }
    }
}