//?https://leetcode.com/problems/painting-a-grid-with-three-different-colors/

//?https://leetcode.com/problems/painting-a-grid-with-three-different-colors/discuss/1330185/C%2B%2BPython-DP-and-DFS-and-Bitmask-Picture-explain-Clean-and-Concise

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int getColor(int mask, int pos) { return (mask >> 2 * pos) & 3; }

int setColor(int mask, int color, int pos) {
  return (mask | (color << (2 * pos)));
}

void dfs(int i, int currState, int prevState, vector<int> &states, int n,
         int m) {
  if (i == m) {
    states.push_back(currState);
    return;
  }
  // 1 - Red. 2 - Green, 3 - Blue

  for (int col = 1; col <= 3; col++) {
    if (getColor(prevState, i) != col and
        (i == 0 or getColor(currState, i - 1) != col)) {
      dfs(i + 1, setColor(currState, col, i), prevState, states, n, m);
    }
  }
}

vector<int> getStates(int colMask, int n, int m) {
  vector<int> states;
  dfs(0, 0, colMask, states, n, m);
  return states;
}

int dp[1001][1025];  // {n, 4^m};

int solve(int i, int prevColMask, int n, int m) {
  if (i == n) return 1;  // Found a valid way to paint whole grid

  if (dp[i][prevColMask] != -1) return dp[i][prevColMask];

  int ans = 0;

  vector<int> possibleStates = getStates(prevColMask, n, m);

  for (auto state : possibleStates) {
    ans = ans + solve(i + 1, state, n, m) % mod;
  }
  return dp[i][prevColMask] = ans;
}

int colorTheGrid(int m, int n) {
  memset(dp, -1, sizeof(dp));
  return solve(0, 0, n, m);
}

signed main() {
  int n, m;
  cin >> n >> m;
  cout << colorTheGrid(m, n) << endl;
}