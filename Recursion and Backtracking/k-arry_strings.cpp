// ?Generate all the possible strings of lenght n from 0 - (k - 1)
#include<bits/stdc++.h>
using namespace std;

void printArray(int *a, int size) {
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void k_strings(int *a, int size, int k, int i) {
    if(i == size) {
        printArray(a, size);
        return;
    }
    for(int j = 0; j < k; j++) {
        a[i] = j;
        k_strings(a, size, k, i + 1);
    }
}

signed main() {
    int n, k;
    cout << "Enter the length of the strings: ";
    cin >> n;
    cout << "Enter the value of k:";
    cin >> k;
    int a[n];
    k_strings(a, n, k, 0);

}