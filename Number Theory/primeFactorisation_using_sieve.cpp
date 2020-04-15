#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primeSieve(int n) {
    int p[n + 1];
    memset(p, 0, sizeof(p));

    if(n >= 2)
        p[2] = 1;

    for(int i = 3; i <=n; i += 2)
        p[i] = 1;
    
    for(int i = 3; i <=n; i += 2) {
        if(p[i]) {
            for(int j = i * i; j <=n; j += i)
                p[j] = 0;
        }
    }
    vector <int> primes;
    primes.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(p[i])
            primes.push_back(i);
    }

    return primes;
}

vector <int> primeFactor(int n) {
    vector <int> primeFactors;
    vector <int> primes = primeSieve(n);
    int i = 0;
    int p = primes[0];

    while(p *p <= n) {
        if(n % p == 0) {
            primeFactors.push_back(p);
            while(n % p == 0) {
                n /= p;
                // primeFactors.push_back(p);
            }
        }
        else {
            i++;
            p = primes[i];
        }
    }

    if(n != 1) {
        primeFactors.push_back(n);
    }
    return primeFactors;

}

signed main() {
    int n;
    cin >> n;
    vector <int> factors = primeFactor(n);

    for(auto i : factors) {
        cout << i << " ";
    }
    cout << "\n";
}