#include<bits/stdc++.h>
using namespace std;
// !Ouput is compiler dependent

void fun(int x, int y, int z) {
    cout << x << " " << y << " " << z << endl;
}

signed main() {
    int i = 1;
    fun(++i, i++, ++i);
    // Evalutuon of parameters is not define in a particular order.
}