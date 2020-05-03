#include<bits/stdc++.h>
using namespace std;
#define int long long

int MaxSubarraySum(vector<int> &v) {
    int n = v.size();
    int maxSum[n];
    maxSum[0] = v[0];
    for(int i = 1; i < n; i++) {
        maxSum[i] = max(v[i], v[i] + maxSum[i - 1]);
    }
    int ans;
    ans = *max_element(maxSum, maxSum + n);

    return ans;

}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
}