#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<int> v;
        vector<int> vv;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] != -1)
            {

                if (i == arr[i])
                {
                    arr[i] = -1;
                    continue;
                }
                int a = arr[i];
                if (arr[a] == i)
                {
                    v.push_back(i);
                    v.push_back(a);
                    arr[i] = -1;
                    arr[a] = -1;
                    continue;
                }
                vv.push_back(i);

                vv.push_back(a);
                int b = arr[a];
                vv.push_back(b);
                arr[i] = arr[b];
                arr[a] = -1;
                arr[b] = -1;
                if (arr[i] != i)
                    i--;
                else
                    arr[i] = -1;
            }
        }

        if (v.size() % 4 != 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (int i = 0; i < v.size(); i += 4)
            {

                vv.push_back(v[i]);
                vv.push_back(v[i + 1]);
                vv.push_back(v[i + 2]);
                vv.push_back(v[i]);
                vv.push_back(v[i + 3]);
                vv.push_back(v[i + 2]);
            }

            int l = vv.size() / 3;
            if (k >= l)
            {
                cout << l << endl;
                for (int i = 0; i < vv.size(); i += 3)
                {
                    cout << vv[i] << " " << vv[i + 1] << " " << vv[i + 2];
                    cout << endl;
                }
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}
