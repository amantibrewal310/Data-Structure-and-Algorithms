#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxSubarrSum(int *a, int n) {
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        currSum += a[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

signed main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << maxSubarrSum(a, n) << endl;
}