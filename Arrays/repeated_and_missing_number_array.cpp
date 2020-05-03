//?https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> repeatedNumber(const vector<int> &v) {
    int n = v.size();
    int sum = ( n * (n + 1) ) / 2, squaredSum = (n * (n + 1) * (2 * n + 1)) / 6;
    int missingNumber = 0, repeating = 0;

    for(int i = 0; i < n; i++) {
        sum -= v[i];
        squaredSum -= v[i] * v[i];
    }

    missingNumber = (sum + squaredSum / sum) / 2;
    repeating = missingNumber - sum;
    vector<int> res;
    res.push_back(repeating);
    res.push_back(missingNumber);

    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> res = repeatedNumber(v);

    cout << res[0] << " " << res[1] << endl;
}