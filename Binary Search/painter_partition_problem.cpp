//?https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isPossible(vector<int> &v, int time, int k) {
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
        if(sum > time) {
            sum = v[i];
            cnt++;
        }
    }
    if(cnt > k)
        return false;
    return true;
}

int solve(vector<int> &v, int k) {
    int mx = *max_element(v.begin(), v.end());
    int sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    int low = mx, high = sum, res = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(v, mid, k)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> k >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cout << solve(v, k) << endl;
    }
}