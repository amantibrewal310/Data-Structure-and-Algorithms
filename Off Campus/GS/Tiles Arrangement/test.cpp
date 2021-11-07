#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &mat, int i, int j, int currState, int prevState,
         int score, int tilesUsed, vector<vector<int>> &states) {
  int m = mat[0].size();
  // cout << "i: " << i << "j: " << j << endl;
  // cout << score << " " << tilesUsed << endl;
  if (j >= m) {
    states.push_back({currState, score, tilesUsed});
    return;
  }
  // left empty
  dfs(mat, i, j + 1, currState, prevState, score, tilesUsed, states);

  int pos = m - (j + 1);

  // For Vertical
  if ((prevState & (1 << pos)) == 0) {
    dfs(mat, i, j + 1, currState | (1 << pos), prevState,
        score + mat[i][j] + mat[i - 1][j], tilesUsed + 1, states);
  }
  if (j < 2) {
    // Put horizontal
    currState |= (1 << pos);
    currState |= (1 << (pos - 1));
    dfs(mat, i, j + 2, currState, prevState, score + mat[i][j] + mat[i][j + 1],
        tilesUsed + 1, states);
  }
}
map<pair<int, int>, vector<vector<int>>> memoState;
vector<vector<int>> getPossibleStates(vector<vector<int>> &mat, int i,
                                      int prevState) {
  vector<vector<int>> states;
  // !State -> {state, score, tilesUsed}
  pair<int, int> key = {i, prevState};
  if (memoState.find(key) != memoState.end()) return memoState[key];
  dfs(mat, i, 0, 0, prevState, 0, 0, states);
  // cout << states.size() << endl;
  return memoState[key] = states;
}

int dp[1001][8][1001];

int solve(vector<vector<int>> &mat, int i, int prevState, int k) {
  int n = mat.size();
  if (k == 0 or i >= n) return 0;

  if (dp[i][prevState][k] != -1) return dp[i][prevState][k];

  auto possibleStates = getPossibleStates(mat, i, prevState);
  int ans = 0;
  for (auto state : possibleStates) {
    // cout << "States" << endl;
    int nextState = state[0];
    int score = state[1];
    int tilesUsed = state[2];

    // cout << nextState << " " << score << " " << tilesUsed << endl;
    if (tilesUsed <= k) {
      ans = max(ans, solve(mat, i + 1, nextState, k - tilesUsed) + score);
    }
  }
  return dp[i][prevState][k] = ans;
}

signed main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> mat(n, vector<int>(3));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> mat[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(mat, 0, 7, k) << endl;
}

/*
5 3
2 1 -1
1 3 2
0 2 3
2 1 1
3 3 0

output = 16
*/