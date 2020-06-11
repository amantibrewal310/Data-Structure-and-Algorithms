#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isValid(vector<int> v, int mx, int k) {
    int cnt = 1, sum = 0;
    for(int i = 0; i < v.size(); i++) {
        if(sum + v[i] > mx) {
            cnt++;
            sum = v[i];
            continue;
        }
        sum += v[i];
    }
    if(cnt <= k)
        return true;
    else
        return false;
}

int solve(vector<int> &v, int m) {
    if(v.size() < m)
        return -1;
    int mx = *max_element(v.begin(), v.end());
    int sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    

    int low = mx, high = sum, res = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        if(isValid(v, mid, m)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

signed main() {
    int n, students;
    cin >> n >> students;
    vector<int> v(n); // Need not be sorted
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v, students) << endl;
}