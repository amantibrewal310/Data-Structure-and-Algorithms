#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Interval {
    int start;
    int end;
    // Interval() : start(0), end(0) {}
    // Interval(int s, int e) : start(s), end(e) {}
};

bool mycomp(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> mergeInterval(vector<Interval> &A) {
    sort(A.begin(), A.end(), mycomp);
    vector<Interval> res;
    int n = A.size();
    int x = A[0].start;
    int y = A[0].end;

    for (int i = 1; i < n; i++)
    {
        if (A[i].start <= y)
        {
            y = max(A[i].end, y);
        }
        else
        {
            Interval temp;
            temp.start = x;
            temp.end = y;
            res.push_back(temp);
            x = A[i].start;
            y = A[i].end;
        }
    }
    Interval temp;
    temp.start = x;
    temp.end = y;
    res.push_back(temp);

    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<Interval> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }

    vector<Interval> res = mergeInterval(v);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
}