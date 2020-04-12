#include<bits/stdc++.h>
using namespace std;

bool isArrayInSortedOrder(int *a, int start, int sizeOfArray) {
    if(sizeOfArray == 1)
        return true;
    else {
        if(a[start] < a[start + 1] && isArrayInSortedOrder(a, start + 1, sizeOfArray - 1))
            return true;
        else
            return false;
    }
}

signed main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(isArrayInSortedOrder(a, 0, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}