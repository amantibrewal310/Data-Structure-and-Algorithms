#include<bits/stdc++.h>
using namespace std;

signed main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    int n = 10;
    vector<int> v1(n, 5);

    vector<int> v2{10, 20, 30, 40};

    // We cannot initialise with the equal to sign.

    int res = *max_element(v.begin(),v.end());
    cout << res << endl;

    int sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    cout << sum << endl;
    // For each loop

    for(int i : v) {
        cout << i << endl;
    }
}