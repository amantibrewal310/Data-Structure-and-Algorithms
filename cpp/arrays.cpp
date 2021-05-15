#include<bits/stdc++.h>
using namespace std;

/*
    Advantages of array

    1. Random Access.
    2. Cache Friendliness.

    Limitations of array

    Most important one is that we need to know the size before we create them
    
    Solution: Vectors in C++

*/

signed main() {
    int n = 6;
    int a[n];
    // cout << "Hello" << endl;
    // cout << a + 0 << endl;
    a[0] = 15;
    a[1] = 15;
    a[2] = 15;
    a[3] = 15;
    a[4] = 15;
    a[5] = 15;

    // int a[2] {10, 20};
    // int arr[5] {10, 20};

    // cout << a[0] << endl;
    // cout << a[1] << endl;
    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;

    //int arr[5] = {0}; // Initialize the array with 0
    //int arr2[5] = {5}; // Initialize the first element as 5 rest as zero same thing happens int the above case.

    // Sum of arrays elements

    int sum = 0;
    sum = accumulate(a, a+n, sum);
    cout << sum << endl;
}