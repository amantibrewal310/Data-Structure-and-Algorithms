// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
// //;cout.tie(NULL) #define ll long long const long double pie
// = 3.14159265358979323846; #define endl '\n' #include
// <ext/pb_ds/assoc_container.hpp> using namespace __gnu_pbds;
// gp_hash_table<int, ll> ma; // orderd_map using pb_ds

// const static int mod = 1e9+7;
// void dfs(int i, int m, vector<int> &prevColState, vector<int> currState,
// vector<vector<int>> &newStates){ 	if(i == m){ 		newStates.push_back(currState);
// 		return;
// 	}
// 	if(i == 0){
// 		for(int col=1;col<=3;col++){
// 			if(prevColState[0] != col){
// 				currState[0] = col;
// 				dfs(i+1, m, prevColState, currState, newStates);
// 			}
// 		}
// 	}
// 	else{
// 		for(int col=1;col<=3;col++){
// 			if(prevColState[i] != col and currState[i-1] != col){
// 				currState[i] = col;
// 				dfs(i+1, m, prevColState, currState, newStates);
// 			}
// 		}
// 	}
// }

// map<vector<int>, vector<vector<int>>> colStateMemo;
// vector<vector<int>> getCurrColStates(vector<int> &prevColState, int m){
// 	if(colStateMemo.find(prevColState) != colStateMemo.end()) return
// colStateMemo[prevColState]; 	vector<vector<int>> newStates; 	vector<int>
// currState(m); 	dfs(0, m, prevColState, currState, newStates); 	return
// colStateMemo[prevColState] = newStates;
// }

// map<pair<int, vector<int>>, int> dp;
// int fun(int col, vector<int> prevColState, int m, int n){
// 	if(col == n) return 1;
// 	if(dp.find({col, prevColState}) != dp.end()) return dp[{col,
// prevColState}]; 	vector<vector<int>> possibleCurrColStates =
// getCurrColStates(prevColState, m); 	int ans = 0; 	for(auto state:
// possibleCurrColStates){ 		ans = (ans%mod + fun(col + 1, state, m, n)%mod)%mod;
// 	}
// 	return dp[{col, prevColState}] = ans;
// }

// void solve(){
// 	int m, n;
// 	cin>>m>>n;
// 	vector<int> colState(m, 0);
// 	cout<<fun(0, colState, m, n);
// }

// signed main(){
// 	#ifndef ONLINE_JUDGE
//     freopen("/mnt/DATA/D_Drive/CP/input.txt", "r", stdin);
//     freopen("/mnt/DATA/D_Drive/CP/output.txt", "w", stdout);
//     #endif

//     fastio;
//     int t=1;
//     //cin>>t;

//     while(--t>=0){
//     	solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)  //;cout.tie(NULL)
#define ll long long
const long double pie = 3.14159265358979323846;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, ll> ma;  // orderd_map using pb_ds

const static int mod = 1e9 + 7;

int getCol(int colState, int pos) { return (colState >> (2 * pos)) & 3; }

int setCol(int colState, int pos, int col) {
  return colState | (col << (2 * pos));
}

void dfs(int i, int m, int prevColState, int currState,
         vector<int> &newStates) {
  if (i == m) {
    newStates.push_back(currState);
    return;
  }
  if (i == 0) {
    for (int col = 1; col <= 3; col++) {
      if (getCol(prevColState, 0) != col) {
        dfs(i + 1, m, prevColState, setCol(currState, 0, col), newStates);
      }
    }
  } else {
    for (int col = 1; col <= 3; col++) {
      if (getCol(prevColState, i) != col and getCol(currState, i - 1) != col) {
        dfs(i + 1, m, prevColState, setCol(currState, i, col), newStates);
      }
    }
  }
}

map<int, vector<int>> colStateMemo;
vector<int> getCurrColStates(int prevColState, int m) {
  if (colStateMemo.find(prevColState) != colStateMemo.end())
    return colStateMemo[prevColState];
  vector<int> newStates;
  int currState = 0;
  dfs(0, m, prevColState, currState, newStates);
  return colStateMemo[prevColState] = newStates;
}

map<pair<int, int>, int> dp;
int fun(int col, int prevColState, int m, int n) {
  if (col == n) return 1;
  if (dp.find({col, prevColState}) != dp.end()) return dp[{col, prevColState}];
  vector<int> possibleCurrColStates = getCurrColStates(prevColState, m);
  int ans = 0;
  for (auto state : possibleCurrColStates) {
    ans = (ans % mod + fun(col + 1, state, m, n) % mod) % mod;
  }
  return dp[{col, prevColState}] = ans;
}

void solve() {
  int m, n;
  cin >> m >> n;
  int colState = 0;
  cout << fun(0, colState, m, n);
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("/mnt/DATA/D_Drive/CP/input.txt", "r", stdin);
  freopen("/mnt/DATA/D_Drive/CP/output.txt", "w", stdout);
#endif

  fastio;
  int t = 1;
  // cin>>t;

  while (--t >= 0) {
    solve();
  }

  return 0;
}