//?https://www.interviewbit.com/problems/minimum-lights-to-activate/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int l = max(0, i - B + 1);
        int r = min(i + B - 1, n - 1);
        cout << l << " " << i << " " << r << endl;

        if(r == i)
            continue;
        
        if(A[r] == 1) {
            cnt++;
            i = r + B - 1;
            continue;
        }
        
        bool flag = 0;
        for(int j = r; j >= l; j--) {
            if(A[j] == 1) {
                flag = 1;
                cnt++;
                i = j + B - 1;
                break;
            }
        }
        if(flag == 0)
            return -1;
    }
    if(cnt == 0) {
        for(int i = 0; i < n; i++) {
            if(A[i] == 1)
                cnt++;
        }
        if(cnt == n)
            return cnt;
        else {
            return -1;
        }
    }
    return cnt;
}

signed main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int &num : nums) {
        cin >> num;
    }

    int range;
    cin >> range;

    cout << solve(nums, range) << endl;
}