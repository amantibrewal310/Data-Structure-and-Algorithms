#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> flip(string s) {
    vector<int> v;
    for(auto i : s) {
        v.push_back(i - '0');
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 0)
            v[i] = 1;
        else if(v[i] == 1)
            v[i] = -1;
    }
    int currSum = 0, maxSum = 0, l = 0, r = 0;
    vector<int> ans;
    for(int i = 0; i < v.size(); i++) {
        currSum += v[i];
        if(currSum < 0) {
            currSum = 0;
            l = i + 1;
            continue;
        }
        if(currSum > maxSum) {
            maxSum = currSum;
            ans = {l + 1, i + 1};
        }
    }
    return ans;
}

signed main() {
    string s;
    cin >> s;
    vector<int> res = flip(s);
    cout << res[0] << " " << res[1] << endl;

}