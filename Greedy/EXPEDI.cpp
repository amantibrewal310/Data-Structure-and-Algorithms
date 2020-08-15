//?https://www.spoj.com/problems/EXPEDI/
#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for(auto &p : v) {
            cin >> p.first >> p.second;
        }

        priority_queue<int> pq;
        sort(v.begin(), v.end(), compare);

        int L, P;
        cin >> L >> P;

        // Update the Distance of the Fuel Station from the truck
        for(int i = 0; i < n; i++) {
            v[i].first = L - v[i].first;
        }

        // prev denotes the prev city we have visited
        int prev = 0;
        int x = 0; // current city
        int cnt = 0;
        bool flag = 1;
        while(x < n) {
            // if we have enough fuel to go to next city
            if(P >= v[x].first - prev) {
                P -= (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            } else {
                // Check if you have some fuelling station visited in the priority queue
                if(pq.empty()) {
                    flag = 0;
                    break;
                } else {
                    P += pq.top();
                    pq.pop();
                    cnt++;
                    continue;
                }
            }
            x++;
        }
        if(flag == 0) {
            cout << -1 << endl;
            continue;
        }
        L = L - v[n - 1].first;
        if(P >= L) {
            cout << cnt << endl;
            continue;
        }
        while(P < L) {
            if(pq.empty()) {
                flag = 0;
                break;
            }
            P += pq.top();
            pq.pop();
            cnt++;
        }
        if(!flag) {
            cout << -1 << endl;
            continue;
        }
        cout << cnt << endl;
    }
}