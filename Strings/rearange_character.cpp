//?https://practice.geeksforgeeks.org/problems/rearrange-characters/0
#include<bits/stdc++.h>
using namespace std;

bool solve(string s) {
    int n = s.length();
    map<char, int> mp;
    for(auto c : s) {
        mp[c]++;
    }
    priority_queue<pair<int, char>> pq;

    for(auto p : mp) {
        pq.push({p.second, p.first});
    }
    string ans = "";

    pair<int ,char> prev = {-1, '#'};

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ans += p.second;

        if(prev.first > 0) {
            pq.push(prev);
        }
        p.first--;
        prev = p;
    }
    if(ans.length() == n) {
        return true;
    }
    return false;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}