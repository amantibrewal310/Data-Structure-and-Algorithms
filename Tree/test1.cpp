#include<bits/stdc++.h>
using namespace std;
int findMedian(vector<vector<int>> &A)
{

    int col = A[0].size();
    int row = A.size();

    int start = INT_MAX, end = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        if (A[i][0] < start)
            start = A[i][0];
    }
    for (int i = 0; i < row; i++)
    {
        if (A[i][col - 1] > end)
            end = A[i][col - 1];
    }

    int ans;
    int count = 0;
    int median = (row * col / 2) + 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        count = 0;

        for (int i = 0; i < row; i++)
        {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }

        if (count < median)
            start = mid + 1;

        else if( count > median)
            end = mid - 1;
        else if(count == median) {
            ans = mid;
            end = mid - 1;
        }

        // count = 0;
    }

    return start;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    findMedian(v);

}