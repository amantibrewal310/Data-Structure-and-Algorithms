#include <bits/stdc++.h>

using namespace std;

void add(int a, int b, map<int, vector<int>> &mp)
{
    mp[a].push_back(b);
    mp[b].push_back(a);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int v, e;
        cin >> v >> e;
        map<int, vector<int>> mp;

        while (e--)
        {
            int a, b;
            cin >> a >> b;
            add(a, b, mp);
        }
        // for(auto p : mp) {
        //     cout << p.first << "----";
        //     vector<int> v1 = p.second;

        //     for(auto i : v1) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        int d[v + 1];
        int vis[v + 1];

        memset(d, -1, sizeof(d));
        memset(vis, 0, sizeof(vis));

        int s;
        cin >> s;

        queue<int> q;

        q.push(s);
        vis[s] = 1;
        d[s] = 0;

        while (q.size() > 0)
        {

            int temp = q.front();
            q.pop();

            for (int i = 0; i < mp[temp].size(); i++)
            {
                if (vis[mp[temp][i]] == 0)
                {

                    q.push(mp[temp][i]);
                    vis[mp[temp][i]] = 1;
                    d[mp[temp][i]] = d[temp] + 1;
                }
            }   
        }

        for (int i = 0; i < v; i++)
        {

            if (d[i] == -1)
            {
                continue;
            }
            else
            {
                d[i] = d[i] * 6;
            }
        }

        // for (int i = s; i < v + s; i++)
        // {
        //     if (d[(i + v) % v] != 0)
        //         cout << d[(i + v) % v] << " ";
        // }
        for(int i = 0; i <= v; i++) {
            cout << d[i] << " ";
        }

        cout << endl;
    }
}