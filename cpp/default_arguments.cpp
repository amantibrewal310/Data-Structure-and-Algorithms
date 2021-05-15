#include<bits/stdc++.h>
using namespace std;

// ! If the function is declare but the definition is missing than compiler will pass the code but the linker will generate the error.

int add(int a, int b, int c = 0, int d = 0) {
    return (a+b+c+d);
}

signed main() {
    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
}