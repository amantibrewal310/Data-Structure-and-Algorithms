#include<bits/stdc++.h>
using namespace std;
#define int long long

/* 
    Segmented Sieve is used when we want to calculate the primes in
    a given range (a, b) is very large. For example, suppose 
        a = 10e10
        b = 10e10 + 10e2
    
    as we couldn't make array of this big size.
    Therefore, we make two arrays.
        First array represent number from a to b
        Second array represent 1 to sqrt(b)

*/

void primeSieve(int *p, int n) {
    for(int i = 3; i <= n; i += 2)
        p[i] = 1;
    for(int i = 3; i <= n; i += 2) {
        if(p[i]) {
            for(int j = i * i; j <= n; j += i)
                p[j] = 0;
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;
}

int segmentedSieve(int a, int b) {

    int n = sqrt(b);
    int p[n + 1];
    memset(p, 0, sizeof(p));
    primeSieve(p, n + 1);

    bool pp[b - a + 1];
    memset(pp, 1, sizeof(pp));

    for(int i = 2; i * i <= b; i++) {
        for(int j = a; j <= b; j++) {
            if(p[i]) {
                if(j == i) // For overlapping part between two arrays
                    continue;
                if(j % i == 0)
                    pp[j - a] = 0;
            }
        }
    }
    if(a == 1)
        pp[0] = 0;

    int res = 0;
    for(int i = a; i <= b; i++)
        res += pp[i - a];

    return res;
}

signed main() {
    int a, b;
    cin >> a >> b;

    cout << segmentedSieve(a, b) << endl;

}