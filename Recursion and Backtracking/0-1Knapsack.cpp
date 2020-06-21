#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    ? 0-1 Knapsack Problem
    -----------------------
*/
int profit(int n, int capacity, vector<int> wt, vector<int> prices) {
    if(capacity <= 0)
        return 0;
    if(n == 0)
        return 0;
    
    int ans = 0;
    int inc, exc;
    inc = exc = INT_MIN;

    if(wt[n - 1] <= capacity)
        inc = prices[n - 1] + profit(n - 1, capacity - wt[n - 1], wt, prices);
    exc = 0 + profit(n - 1, capacity, wt, prices);
    ans = max(inc ,exc);
    return ans;
}

signed main() {
    int n, c;
    cin >> n >> c;
    vector<int> wt(n), prices(n);
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    cout << profit(n, c, wt, prices) << endl;


}