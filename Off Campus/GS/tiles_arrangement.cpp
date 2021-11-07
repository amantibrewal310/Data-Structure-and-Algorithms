#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(vector<vector<int>> &mat, int i, int j, int score, int tilesUsed,
         int currState, int prevState, vector<vector<int>> &states) {
  int n = mat.size();
  int m = mat[0].size();

  if (j == m) {
    states.push_back({currState, tilesUsed, score});
    return;
  }

  // Leave Empty
  dfs(mat, i, j + 1, score, tilesUsed, currState, prevState, states);

  // Put Vertically
  int pos = m - j - 1;

  if ((prevState & (1 << pos)) == 0) {
    dfs(mat, i, j + 1, score + mat[i - 1][j] + mat[i][j], tilesUsed + 1,
        currState | (1 << pos), prevState, states);
  }

  // Put Horizontally
  if (j < 2) {
    currState |= (1 << pos);
    currState |= (1 << (pos - 1));
    dfs(mat, i, j + 2, score + mat[i][j] + mat[i][j + 1], tilesUsed + 1,
        currState, prevState, states);
  }
}

map<pair<int, int>, vector<vector<int>>> memoStates;

vector<vector<int>> getStates(vector<vector<int>> &mat, int i, int prevState) {
  pair<int, int> key = {i, prevState};

  if (memoStates.find(key) != memoStates.end()) return memoStates[key];

  vector<vector<int>> states;

  int currState = 0;
  int score = 0;
  int tilesUsed = 0;
  dfs(mat, i, 0, score, tilesUsed, currState, prevState, states);

  return memoStates[key] = states;
}

int dp[1001][1001][8];

int solve(vector<vector<int>> &mat, int i, int prevState, int k) {
  int n = mat.size();

  if (k == 0) return 0;
  if (i >= n) return INT_MIN / 2;

  if (dp[i][k][prevState] != -1) return dp[i][k][prevState];

  vector<vector<int>> possileStates = getStates(mat, i, prevState);

  int ans = INT_MIN / 2;

  for (auto state : possileStates) {
    int newState = state[0];
    int tilesUsed = state[1];
    int score = state[2];
    if (tilesUsed <= k) {
      ans = max(ans, score + solve(mat, i + 1, newState, k - tilesUsed));
    }
  }
  return dp[i][k][prevState] = ans;
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
  cout << solve(mat, 0, 7, k) << endl;
}