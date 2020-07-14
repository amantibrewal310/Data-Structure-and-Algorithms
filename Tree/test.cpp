#include<bits/stdc++.h>
using namespace std;
int search(const vector<int> &A, int B)
{

    int start = 0;
    int end = A.size() - 1;
    int pivot;
    int mid;
    int N = A.size();
    int ans1, ans2;

    if (A[start] > A[end])
    {
        while (start <= end)
        {
            if(A[start] <= A[end]) {
                pivot = start;
                break;
            }
            mid = start + (end - start) / 2;
            int next = (mid + 1) % N;
            int prev = (mid - 1 + N) % N;
            // cout << next << " " << prev << endl;
            // cout << A[next] << " " << A[prev] << endl;

            if (A[mid] <= A[prev] && A[mid] <= A[next])
            {
                cout << " hello " << endl;
                pivot = mid;
                break;
            }

            else if (A[start] <= A[mid])
                start = mid + 1;

            else if (A[end] >= A[mid])
                end = mid - 1;
        }
        // cout << pivot << endl;

        int start = 0;
        int end = pivot - 1;
        ans1 = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (B == A[mid]) {
                ans1 = mid;
                break;
            }

            else if (B > A[mid])
                start = mid + 1;

            else
                end = mid - 1;
        }
        // cout << ans1 << endl;

        start = pivot;
        end = A.size() - 1;
        ans2 = -1;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (B == A[mid]) {
                ans2 = mid;
                break;
            }

            else if (B > A[mid])
                start = mid + 1;

            else
                end = mid - 1;
        }

        if (ans1 == -1 && ans2 == -1)
            return -1;

        else if (ans1 == -1)
            return ans2;

        else if (ans2 == -1)
            return ans1;
    }

    start = 0;
    end = N - 1;

    if (A[start] < A[end])
    {

        while (start <= end)
        {
            mid = (start + end) / 2;

            if (A[mid] == B)
                return mid;

            else if (A[mid] > B)
                end = mid - 1;

            else if (A[mid] < B)
                start = mid + 1;
        }

        return mid;
    }
    return -1;
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int key;
    cin >> key;
    cout << search(v, key) << endl;
}