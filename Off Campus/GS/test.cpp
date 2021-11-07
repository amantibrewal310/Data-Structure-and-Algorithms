#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> mat, int i, int j, int currState, int prevState,
         int score, int tilesCount, vector<vector<int>> &states) {
  if (j == 3) {
    states.push_back({currState, score, tilesCount});
    return;
  }
  cout << "hello" << endl;
  cout << "j: " << j << endl;
  cout << currState << " " << prevState << " " << score << " " << tilesCount
       << endl;

  // Leave empty
  dfs(mat, i, j + 1, currState, prevState, score, tilesCount, states);

  // Put vertically;
  if (i != 0) {
    if ((prevState & (1 << j)) == 0) {
      dfs(mat, i, j + 1, currState | (1 << j), prevState,
          score + mat[i][2 - j] + mat[i - 1][2 - j], tilesCount + 1, states);
    }
  }

  // horizontally
  if (j != 2) {
    currState |= (1 << j);
    currState |= (1 << j + 1);
    dfs(mat, i, j + 2, currState, prevState,
        score + mat[i][2 - j] + mat[i][2 - j - 1], tilesCount + 1, states);
  }
}

map<pair<int, int>, vector<vector<int>>> memoStates;

vector<vector<int>> getPossibleStates(vector<vector<int>> &mat, int i,
                                      int prevState) {
  if (memoStates.find({i, prevState}) != memoStates.end())
    return memoStates[{i, prevState}];
  vector<vector<int>> states;
  dfs(mat, i, 0, 0, prevState, 0, 0, states);
  cout << "i: " << i << " prevState" << prevState << endl;
  for (auto state : states) {
    cout << state[0] << " " << state[1] << " " << state[2] << endl;
  }
  return memoStates[{i, prevState}] = states;
}

int dp[1001][1001][8];

int solve(vector<vector<int>> &mat, int i, int prevState, int currTilesCount,
          int tilesCount) {
  int n = mat.size();

  if (currTilesCount > tilesCount) {
    return INT_MIN / 2;
  }
  if (currTilesCount == tilesCount) return 0;
  if (i >= n) return INT_MIN / 2;

  if (dp[i][currTilesCount][prevState] != -1)
    return dp[i][currTilesCount][prevState];
  cout << "i: " << i << endl;
  vector<vector<int>> possibleStates = getPossibleStates(mat, 0, prevState);

  int ans = INT_MIN;

  for (auto state : possibleStates) {
    int score = state[1];
    int tileUsed = state[2];
    int newState = state[0];

    cout << score << " " << tileUsed << " " << newState << endl;

    ans = max(ans, score + solve(mat, i + 1, newState,
                                 currTilesCount + tileUsed, tilesCount));
  }

  return dp[i][currTilesCount][prevState] = ans;
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
  memoStates.clear();
  cout << solve(mat, 0, 7, 0, k) << endl;
}