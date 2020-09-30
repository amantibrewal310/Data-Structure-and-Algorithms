#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int n) {
    if(n == 1) {
        return {"0", "1"};
    }
    vector<string> temp = solve(n - 1); // result of n - 1 bits
    vector<string> ans;

    for(int i = 0; i < temp.size(); i++) {
        string s = temp[i];
        ans.push_back("0" + s);
    }
    for(int i = temp.size() - 1; i >= 0; i--) {
        string s = temp[i];
        ans.push_back("1" + s);
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<string> ans = solve(n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}