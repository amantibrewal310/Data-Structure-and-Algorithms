// ?Generate all the binary strings with n bits
#include<bits/stdc++.h>
using namespace std;

void printArray(int *a, int size) {
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bitStrings(int *a, int size, int i) {
    if(i == size) {
        printArray(a, size);
        return;
    }
    // First assign "0" at the ith position and check rest of the permutations
    a[i] = 0;
    bitStrings(a, size, i + 1);
    // Now assign "1" at the ith position and check rest of the permutations
    a[i] = 1;
    bitStrings(a, size, i + 1);
}

signed main() {
    int n;
    cout << "Enter the number of bits:";
    cin >> n;
    int a[n];
    bitStrings(a, n, 0);
}