#include<bits/stdc++.h>
using namespace std;
#define int long long

bool hotel(vector<int> &arrive, vector<int> &depart, int k) {

    vector<pair<int, int> > bookings;

    for(int i = 0; i < arrive.size(); i++) {
        bookings.push_back(make_pair(arrive[i], depart[i]));
    }
    // cout << bookings.size();

    sort(bookings.begin(), bookings.end());

    // for(int i = 0; i < bookings.size(); i++) {
    //     cout << bookings[i].first << " " << bookings[i].second << endl;
    // }

    priority_queue<int, vector<int>, greater<int>> s;
    s.push(bookings[0].second);

    for(int i = 1; i < bookings.size(); i++) {
        if (bookings[i].first == bookings[i].second)
            continue;
        if(bookings[i].first == bookings[i - 1].first) {
            s.push(bookings[i].second);
            if (s.size() > k)
            {
                return 0;
            }
            continue;
        }
        else if(s.top() > bookings[i].first)
            s.push(bookings[i].second);
        else {
            while(s.size() > 0 && s.top() <= bookings[i].first)
                s.pop();
            s.push(bookings[i].second);
        }

        if(s.size() > k) {
            return 0;
        }
    }
    return 1;

}

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> arrive(n);
    vector<int> depart(n);

    for(int i = 0; i < n; i++)
        cin >> arrive[i];
    
    for(int i = 0; i < n; i++)
        cin >> depart[i];

    cout << hotel(arrive, depart, k) << endl;
}