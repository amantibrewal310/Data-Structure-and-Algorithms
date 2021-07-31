#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[1001][(1 << 10) + 1];
map<int, vector<int>> memoStates;

void dfs(int i, int currState, int prevState, vector<int> &states, int n) {
  if (i == n) {
    states.push_back(currState);
    return;
  }

  // Put Vertically
  int pos = n - i - 1;

  if ((prevState & (1 << pos)) == 0) {
    dfs(i + 1, currState | (1 << pos), prevState, states, n);
  } else {
    // Leave Empty
    dfs(i + 1, currState, prevState, states, n);

    // Put horizontally
    if (i < n - 1 and (prevState & (1 << (pos - 1)))) {
      currState |= (1 << pos);
      currState |= (1 << (pos - 1));
      dfs(i + 2, currState, prevState, states, n);
    }
  }
}

vector<int> getStates(int prevState, int n) {
  // pair<int, int> key = {i, prevState};
  if (memoStates.find(prevState) != memoStates.end())
    return memoStates[prevState];
  vector<int> states;

  dfs(0, 0, prevState, states, n);
  // for (auto state : states) {
  //   cout << state << endl;
  // }
  return memoStates[prevState] = states;
}

int solve(int i, int prevState, int n, int m) {
  if (i == m) return prevState == ((1 << n) - 1);

  if (dp[i][prevState] != -1) return dp[i][prevState];

  vector<int> possibleState = getStates(prevState, n);

  int ans = 0;

  for (auto state : possibleState) {
    ans = (ans + solve(i + 1, state, n, m)) % mod;
    // cout << ans << endl;
  }
  return dp[i][prevState] = ans;
}

signed main() {
  int n, m;
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  memoStates.clear();
  cout << solve(0, (1 << n) - 1, n, m) << endl;
}