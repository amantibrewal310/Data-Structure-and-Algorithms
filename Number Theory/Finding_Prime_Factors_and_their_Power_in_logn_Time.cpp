#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
const long double pie = 3.14159265358979323846;
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, ll> ma; // orderd_map using pb_ds

const int N = 1e6 + 1;
int SP[N];
/*
	Approach:
		1. Using Sieve we need to fill the SP array once.
		2. SP[i] is the smallest prime factor to i.
		3. So, SP can be filled in O(n*log(log(n))) time.
		4. After that we can find for each number x what are its
		   prime factors and their powers.
*/

bool isPrime[N];
void sieve(){ // used to fill the SP array.
	memset(isPrime, 1, sizeof(isPrime));
	memset(SP, -1, sizeof(SP));
	isPrime[0] = 0;
	isPrime[1] = 0; 

	for(ll i=2;i<N;i++){
		if(isPrime[i]){
			SP[i] = i;
			for(ll j=i*i;j<N;j+=i){
				if(SP[j] == -1)
					SP[j] = i;
				isPrime[j] = 0;
			}
		}
	}

}

// Takes log(n) time.
vector<pair<int, int>> find_PFacs_and_Powers(int n){
	vector<pair<int, int>> ans;
	int curr_prime_fac = SP[n];
	int curr_power = 1;
	while(n>1){
		n = n/SP[n];
		if(SP[n] == curr_prime_fac){
			curr_power++;
		}
		else{
			ans.push_back({curr_prime_fac, curr_power});
			curr_prime_fac = SP[n];
			curr_power = 1;
		}

	}
	return ans;
}

void solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> ans = find_PFacs_and_Powers(n);
	cout<<"Factors and Powers:"<<endl;
	for(auto pa: ans){
		cout<<pa.first<<" : "<<pa.second<<endl;
	}
}
signed main(){
	#ifndef ONLINE_JUDGE
    freopen("/mnt/DATA/D_Drive/CP/input.txt", "r", stdin);
    freopen("/mnt/DATA/D_Drive/CP/output.txt", "w", stdout);
    #endif
    fastio;
    int t=1;
    cin>>t;
    sieve();
    while(--t>=0){
    	solve();
    }
		

    return 0;
}