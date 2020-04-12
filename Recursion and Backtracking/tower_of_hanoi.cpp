#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int numberOfDisk, int start, int end) {
    if(numberOfDisk) {
        int k = 6 - start - end;
        towerOfHanoi(numberOfDisk - 1, start, k);
        cout << "Move Disk " << numberOfDisk << " from " << start << " to " << end << endl;
        towerOfHanoi(numberOfDisk - 1, k, end);
    }
}

signed main() {
    int n;
    cout << "Enter the number of Disks: ";
    cin >> n;
    towerOfHanoi(n, 1, 3);
    
}