//?https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0
#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int> &v) {
    int n = v.size();
    int l = 0, r = n - 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(mid > 0 and mid < n - 1) {
            if(v[mid] > v[mid + 1] and v[mid] > v[mid - 1])
                return v[mid];
            else if(v[mid + 1] > v[mid])
                l = mid + 1;
            else if(v[mid - 1] > v[mid])
                r = mid - 1;
        } else if(mid == 0) {
            if(v[0] > v[1])
                return v[0];
            else
                return v[1];
        } else if(mid == n - 1) {
            if(v[n - 1] > v[n - 2])
                return v[n - 1];
            else 
                return v[n - 2];
        }
        
    }
    return v[l];
}
signed main()
 {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++)
	        cin >> v[i];
	    cout << findMax(v) << endl;
	   
	}
	
}