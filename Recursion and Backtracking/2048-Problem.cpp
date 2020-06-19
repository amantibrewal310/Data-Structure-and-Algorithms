#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem : Number to Spellings

string numInWord(int n) {
    string ans = "";
    switch (n)
    {
    case 1:
        ans = "One";
        break;
    case 2:
        ans = "Two";
        break;
    case 3:
        ans = "Three";
        break;
    case 4:
        ans = "Four";
        break;
    case 5:
        ans = "Five";
        break;
    case 6:
        ans = "Six";
        break;
    case 7:
        ans = "Seven";
        break;
    case 8:
        ans = "Eight";
        break;
    case 9:
        ans = "Nine";
        break;
    default:
        ans = "Zero";
        break;
    }
    return ans;
}

void printSpelling(int n) {
    if(n / 10 == 0) {
        cout << numInWord(n) << " ";
        return;
    }
    printSpelling(n / 10);
    printSpelling(n % 10);
}

signed main() {
    int n;
    cin >> n;
    printSpelling(n);
    cout << endl;

}