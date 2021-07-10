#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &stations, int i, int currFuel, int target,
          int finalTarget) {
  if (currFuel >= target) {
    return 0;
  }
  int ans = INT_MAX;

  for (int j = i; j < stations.size(); j++) {
    int disTraveled = finalTarget - target;
    int dis = stations[j][0] - disTraveled;
    int fuel = stations[j][1];

    if (currFuel - dis >= 0) {
      ans = min(ans, 1 + solve(stations, i + 1, currFuel - dis, target - dis,
                               finalTarget));
    }
  }
  return ans;
}

signed main() {}