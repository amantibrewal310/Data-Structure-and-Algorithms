//?https://practice.geeksforgeeks.org/problems/number-of-occurrence/0
#include <bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int> &v, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x == v[mid])
            return mid;
        else if (x > v[mid])
            return binarySearch(v, mid + 1, high, x);
        else if (x < v[mid])
            return binarySearch(v, low, mid - 1, x);
    }

    return -1;
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
        int l = -1, r = n;
        // cin >> x;
        if (binarySearch(v, 0, n - 1, x) != -1)
        {
            l = r = binarySearch(v, 0, n - 1, x);
            while (binarySearch(v, 0, l - 1, x) != -1)
            {
                l = binarySearch(v, 0, l - 1, x);
            }
            while (binarySearch(v, r + 1, n - 1, x) != -1)
                r = binarySearch(v, r + 1, n - 1, x);
        }

        if (r - l + 1 <= n)
            cout << r - l + 1 << endl;
        else
            cout << -1 << endl;
    }
}