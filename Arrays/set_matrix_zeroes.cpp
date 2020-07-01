#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    bool is_col = false;

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] == 0)
            is_col = true;
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (!matrix[i][0] or !matrix[0][j])
                matrix[i][j] = 0;
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (is_col)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
}