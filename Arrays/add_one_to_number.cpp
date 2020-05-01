#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    vector<int> ans(n);
    ans[n - 1] = digits[n -1] + 1;
    int carry = ans[n - 1] / 10;
    ans[n - 1] = ans[n -1] % 10;

    for(int i = n - 2; i >= 0; i--) {
        ans[i] = digits[i] + carry;
        carry = ans[i] / 10;
        ans[i] = ans[i] % 10;
    }

    if(carry) {
        ans.insert(ans.begin(), 1);
    }
    int cntZero = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != 0)
            break;
        cntZero++;
    }
    vector<int> res(ans.begin() + cntZero, ans.end());
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> digits(n);
    for(int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    vector<int> res = plusOne(digits);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}