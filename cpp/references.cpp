#include<bits/stdc++.h>
using namespace std;

// Reference is internally implemented using const pointer. So, it must initailize at the time of declaration.

int &fun() {
    static int x = 10;
    // Never return non static variable as a reference.
    return x;
}

signed main() {

    int x = 10;
    int &y = x;
    cout << y << endl;
    x = x + 5;
    cout << y << endl;

    /*
        Use to avoid copy of large objects during
    */

   vector<int> vect{10, 20, 30, 40};
   for(auto x : vect)
    x += 5;

    for(auto x : vect)
        cout << x << " "; 
    // Ouput is no change in the vectors elements.

    int &z = fun();
    cout << fun() << endl;
    z = 30;
    cout << fun();
}