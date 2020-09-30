//?https://www.youtube.com/watch?v=yr77dVf1RQA
#include<bits/stdc++.h>
using namespace std;
unordered_set<string> dict;
vector<vector<int>> dp;


// O(n ^ 3)
bool solve(string s, int i, int j) {
    if(i > j) {
        return false;
    }
    
    string t(s.begin() + i, s.begin() + j + 1);
    
    if(dict.find(t) != dict.end())
        return true;
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    for(int k = i; k < j; k++) {
        bool tmp = solve(s, i, k) and solve(s, k + 1, j);
        if(tmp) return dp[i][j] = true;
    }
    return dp[i][j] = false;
}
int go(int start, string &s, unordered_set<string> &dict, vector<int> &dp) {

  if(start == s.length()) {
        return 1;
  }
  if(dp[start] != -1) {
        return dp[start];
  }
  string curr = "";
  int ans = 0;
  for(int i=start; i<s.length(); i++) {
        curr.push_back(s[i]);
        if(dict.count(curr)) {
              ans |= go(i+1, s, dict, dp);
        }
  }
  dp[start] = ans;
  return dp[start];
}

bool wordBreak(string s, vector<string>& wordDict) {
    dict.clear();
    dp.clear();
    
    int n = s.length();
    
    dp.assign(n, vector<int>(n, -1));
    
    for(auto word : wordDict) {
        dict.insert(word);
    }
    
    return solve(s, 0, n - 1);
    
}
signed main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> dict(n);

    for(auto &word : dict) {
        cin >> word;
    }

    cout << wordBreak(s, dict) << endl;
}