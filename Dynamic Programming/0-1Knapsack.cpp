//?https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

// Memoizations
int knapsack(vector<int> &weights, vector<int> &prices, int capacity, int n) {
    if(n < 0 or capacity == 0)
        return 0;
    
    if(dp[n][capacity] != -1) {
        return dp[n][capacity];
    }
    if(weights[n] <= capacity) {
        return dp[n][capacity] = max(prices[n] + knapsack(weights, prices, capacity - weights[n], n - 1), knapsack(weights, prices, capacity, n - 1));
    }
    return dp[n][capacity] = knapsack(weights, prices, capacity, n - 1);
}

// Top Down

int knapsackTD(vector<int> &weight, vector<int> &prices, int capacity, int n) {
    int dp[n + 1][capacity + 1];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weight[i - 1] <= j) {
                dp[i][j] = max(prices[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}



signed main() {
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    vector<int> weights(n), prices(n);
    for (auto &price : prices) {
        cin >> price;
    }
    for (auto &weight : weights) {
        cin >> weight;
    }
    
    memset(dp, -1, sizeof(dp));

    cout << knapsack(weights, prices, capacity, n - 1) << endl;
    cout << knapsackTD(weights, prices, capacity, n) << endl;
    
}