#include<bits/stdc++.h>
using namespace std;
#define int long long

int countRotations(vector<int> &v, int low, int high) {
    if(high < low)
        return 0;
    if(high == low)
        return low;
    int mid = low + (high - low) / 2;
    if(mid < high && v[mid + 1] < v[mid])
        return mid + 1;
    if(mid > low && v[mid] < v[mid - 1])
        return mid;
    
    if(v[high] > v[mid])
        return countRotations(v, low, mid - 1);
    return countRotations(v, mid + 1, high);

}
int findMin(const vector<int> &A)
{
    int low = 0, high = A.size() - 1;
    int len = A.size();
    while (low <= high)
    {
        if (A[low] <= A[high])
            return A[low]; // Case 1
        int mid = (low + high) / 2;
        int next = (mid + 1) % len, prev = (mid + len - 1) % len;
        if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
            return A[mid];
        else if (A[mid] <= A[high])
            high = mid - 1; // Case 3
        else if (A[mid] >= A[low])
            low = mid + 1; // Case 4
    }
    return -1;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << findMin(v) << endl;
    cout << countRotations(v, 0, n - 1) << endl;
}