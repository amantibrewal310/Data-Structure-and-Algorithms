#include<bits/stdc++.h>
using namespace std;

int firstOcc(int *a, int n, int key) {
    if(n == 0)
        return -1;
    if(a[0] == key)
        return 0;
    int i = firstOcc(a + 1, n - 1, key);
    if(i == -1)
        return -1;
    return i + 1;
}

int lastOcc(int *a, int n, int key) {
    if(n == 0)
        return -1;
    int i = lastOcc(a + 1, n - 1, key);
    if(i == -1) {
        if(a[0] == key)
            return 0;
        else 
            return -1;
    }
    return i + 1;
}

void allOcc(int *a, int i, int n, int key) {
    if(i == n)
        return;
    if(a[i] == key)
        cout << i << " ";
    allOcc(a, i + 1, n, key);
}

int linearSearch(int *a, int i, int n, int key) {
    if(i  == n)
        return -1;
    if(a[i] == key) {
        return i;
    }
    return linearSearch(a, i + 1, n, key);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << firstOcc(a, n, key) << endl;
    cout << lastOcc(a, n, key) << endl;
    allOcc(a, 0, n, key);
}