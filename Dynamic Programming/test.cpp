#include<bits/stdc++.h>
using namespace std;

int dp[100005];

int solve(vector<int> &fees, int i) {
	if(dp[i] != -1)
        return dp[i];
    
    if(i == 0)
        return dp[i] = 0;
    if(i == 1) 
        return dp[i] = fees[0];
    if(i == 2)
        return dp[i] = fees[1] + fees[0];
    
    return dp[i] = max({solve(fees, i - 1), fees[i - 1] + solve(fees, i - 2), fees[i - 2] + fees[i - 1] + solve(fees, i - 3)});
}

signed main() {
	int n;
	cin >> n;
	vector<int> fees(n);
	for(int &fee : fees)
		cin >> fee;
    memset(dp, -1, sizeof(dp));
	cout << solve(fees, n) << endl;
	
}