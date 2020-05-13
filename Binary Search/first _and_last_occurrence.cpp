//?https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0
#include <bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int> &v, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (x == v[mid])
        return mid;
    else if (x > v[mid])
        return binarySearch(v, mid + 1, high, x);
    else if (x < v[mid])
        return binarySearch(v, low, mid - 1, x);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        // cin >> x;
        vector<int> res = {-1, -1};
        if (binarySearch(v, 0, n - 1, x) != -1)
        {
            res[0] = res[1] = binarySearch(v, 0, n - 1, x);
            while (binarySearch(v, 0, res[0] - 1, x) != -1)
            {
                res[0] = binarySearch(v, 0, res[0] - 1, x);
            }
            while (binarySearch(v, res[1] + 1, n - 1, x) != -1)
            {
                res[1] = binarySearch(v, res[1] + 1, n - 1, x);
            }
        }
        if (res[0] == -1 && res[1] == -1)
            cout << -1 << endl;
        else
            cout << res[0] << " " << res[1] << endl;
    }
}