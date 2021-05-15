#include <bits/stdc++.h>
using namespace std;
/*
    ! When Variable is not initialized with any value then in
    c - Garbage value i.e random value is stored
    c++ - 0 as the default value for global and static variable.
*/

int x;

signed main()
{
    /*
        In c++ sizeof datatype depends on the complier their is no standard is define for specific sizeof the variable.
    */
    int y;
    cout << y << endl;
    cout << sizeof(char) << endl;
    int x = 10;
    {
        int x = 20;
        cout << x << endl;
        /*
            ! It will print 20 because the closest scope value of x is 20. {} - define the scope.
        */
    }
    cout << x << endl;

    /*
        ? What is the solution for using same local variable in defferent scope is static variable.
    */
}