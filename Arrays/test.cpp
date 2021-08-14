#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int dp[110][110];
  int vis[100];
  int maxHeightOfBoxes = 0;

  int traverseArray(int height[], int width[], int length[], int n,
                    int prevLength, int prevWidth) {
    int mxH = 0;
    if (dp[prevLength][prevWidth] != -1) return dp[prevLength][prevWidth];
    for (int j = 0; j < n; j++) {
      if (length[j] < prevLength && width[j] < prevWidth)
        mxH = max(mxH, height[j] + traverseArray(height, width, length, n,
                                                 length[j], width[j]));
      if (width[j] < prevLength && length[j] < prevWidth)
        mxH = max(mxH, height[j] + traverseArray(height, width, length, n,
                                                 width[j], length[j]));
      if (length[j] < prevLength && height[j] < prevWidth)
        mxH = max(mxH, width[j] + traverseArray(height, width, length, n,
                                                length[j], height[j]));
      if (height[j] < prevLength && length[j] < prevWidth)
        mxH = max(mxH, width[j] + traverseArray(height, width, length, n,
                                                height[j], length[j]));
      if (height[j] < prevLength && width[j] < prevWidth)
        mxH = max(mxH, length[j] + traverseArray(height, width, length, n,
                                                 height[j], width[j]));
      if (width[j] < prevLength && height[j] < prevWidth)
        mxH = max(mxH, length[j] + traverseArray(height, width, length, n,
                                                 width[j], height[j]));
    }

    return dp[prevLength][prevWidth] = mxH;
  }
  int maxHeight(int height[], int width[], int length[], int n) {
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    return traverseArray(height, width, length, n, 105, 105);
  }
};

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int A[105], B[105], C[105];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < n; j++) cin >> B[j];
    for (int k = 0; k < n; k++) cin >> C[k];
    Solution ob;
    cout << ob.maxHeight(A, B, C, n) << endl;
  }

  return 0;
}