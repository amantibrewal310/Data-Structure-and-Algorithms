#include<bits/stdc++.h>
using namespace std;
#define int long long

void prime_sieve(int *p, int n) {

    //first mark all odd number's prime as they can be potential prime number

    for(int i = 3; i <= n; i += 2) {
        p[i] = 1;
    }

    // Sieve
    for(int i = 3; i <= n; i += 2) {
        //If the current number is not marked (it is prime)
        if(p[i] == 1) {
            // mark all the multiples of i as not prime
            for(int j = i * i; j <= n; j = j + i) {
                p[j] = 0;
            }
        }
    }

    // Special case
    p[2] = 1;
    p[1] = p[0] = 0;

}

signed main() {
    int n;
    cin >> n;

    int p[n + 1] = {0};
    prime_sieve(p, n);

    for(int i = 0; i <= n; i++) {
        if(p[i] == 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
}