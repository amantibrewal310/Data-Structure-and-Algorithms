#include<bits/stdc++.h>
using namespace std;
#define int long long

int fibonacci(int n) {
    if(n == 0 or n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

signed main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}