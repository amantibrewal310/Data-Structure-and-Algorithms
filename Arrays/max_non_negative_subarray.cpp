#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> maxSet(vector<int> &a) {
    long long int currSum = 0, maxSum = 0, startMax = -1, endMax = -1, l = 0, r = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] > - 1) {
            currSum += a[i];
            if(currSum > maxSum) {
                maxSum = currSum;
                startMax = l;
                endMax = i + 1;
            }
            else if(currSum == maxSum) {
                if(i + 1 - l  > endMax - startMax) {
                    startMax = l;
                    endMax = i + 1;
                }
            }
        }
        else {
            currSum = 0;
            l = i + 1;
        }
    }
    vector<int> ans;
    if(startMax == -1 or endMax == -1)
        return ans;
    for(int i = startMax; i < endMax; i++)
        ans.push_back(a[i]);
    return ans;
    
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans = maxSet(a);
    cout << ans.size();
    cout << ans[0] << " " << ans[1] << endl;
}