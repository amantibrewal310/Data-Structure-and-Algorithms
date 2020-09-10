#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.first / (1.0 * a.second);

    double r2 = (double)b.first / (1.0 * b.second);

    return r1 > r2;
}

double fractionalKnapsack(vector<pair<int, int>> &v, int capacity) {
    int n = v.size();
    int currentCapacity = 0;
    double val = 0;

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        if(currentCapacity + v[i].second <= capacity) {
            currentCapacity += v[i].second;
            val += (double)v[i].first;
        } else {
            int rem = capacity - currentCapacity;
            double tmp = (double)v[i].first / (1.0 * v[i].second);
            tmp *= rem;
            val += tmp;
        }
    }
    return val;

}

signed main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    double res = fractionalKnapsack(v, capacity);

    cout << res << endl;
}