#include <bits/stdc++.h>
using namespace std;
/*
    ! We should use post increment and pre increment carefully
    For example : If we use mutiple instance of this operator than it may be complier dependent. Like if we consiser z = x++++x then output of this expression is complier dependent complier is free to choose the sequence.
    More example are : z = x++/x++
                       z = x++ * ++x
*/
signed main() {
    int x = 10;
    int y = 20;
    int p = 30;
    int l;
    // int z = x++++x;
    // cout << z << endl;

    // Normal TypeCasting.
    // double z = (double) x/y;
    // Output : 0.5
    // static_cast<data_type> - it does some extra check i.e first it check wheather the value can be typecast or not then only it typecast.
    double z = static_cast<double> (x/y);
    // output : 0
    cout << z << endl;

    // Short circuiting 

    bool res = (x == 4) && (x++);
    cout << res << " " << x << endl;

    int k = (x, y, p);
    cout << k << endl;
    // Output is 30 because comma operator have least priority.

    // int l = x, y, p;  -- !Giving redeclaration error
    l = x, y, p;
    cout << l << endl;

    if( x > y > p) {
        cout << "Yes" << endl;
    }
    else
    {
            cout << "No" << endl;
    }

    // Output is NO because x > y will become 1 as it is true than 1 > p is execute which is false.
    

}