//?https://leetcode.com/problems/subarray-sums-divisible-by-k/
//?https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k/0
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> pre(n, 0);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    int freq[k];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        pre[i] = (pre[i] % k + k) % k;
        freq[pre[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int t = freq[i];
        if (t > 1)
        {
            ans += t * (t - 1) / 2;
        }
    }
    ans += freq[0];
    return ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << solve(v, k) << endl;
    }
}