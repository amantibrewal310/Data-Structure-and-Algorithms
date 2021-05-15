#include<bits/stdc++.h>
using namespace std;

int makeChange(vector<int> coins, int money) {
    int n = coins.size();

    int ans = 0;

    while(money > 0) {
        int idx = upper_bound(coins.begin(), coins.end(), money) - coins.begin() - 1;

        // cout << coins[idx] << " + ";
        money -= coins[idx];
        ans++;
    }
    return ans;

}

signed main() {
    int n;
    cin >> n;

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    cout << "No of trasactions : " << endl;
    cout << makeChange(coins, n) << endl;
}