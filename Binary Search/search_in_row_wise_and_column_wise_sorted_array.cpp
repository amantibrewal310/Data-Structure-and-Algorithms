//?https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> searchMatrix(vector<vector<int> > &mat, int key) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = mat[0].size() - 1;
    pair<int, int> p = {-1, -1};
    while(i >= 0 and i < n and j >= 0 and j < m) {
        if(mat[i][j] == key) {
            return pair<int, int> {i, j};
        }
        else if(mat[i][j] > key)
            j--;
        else if(mat[i][j] < key)
            i++;
    }
    return p;
}

signed main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int> > mat(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];
    }
    int key;
    cin >> key;
    pair<int, int> res = searchMatrix(mat, key);
    cout << res.first << " " << res.second << endl;


}