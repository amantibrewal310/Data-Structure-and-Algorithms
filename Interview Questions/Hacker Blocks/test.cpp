#include <bits/stdc++.h>
using namespace std;

vector<int> dir{0, 1, 0, -1, 0};

//stores elements that became 1 or were already 1.
std::queue<pair<int, int>> q;

//to get any island
void DFS(vector<vector<int>> &A, vector<vector<int>> &dist, int row, int col)
{ //change it to -1 so that we don't add it more than once.
    A[row][col] = -1;
    //distance[i][j] means flips done to make it 1, as it was already 1 hence it is 0.
    dist[row][col] = 0;
    q.push(make_pair(row, col));
    for (int i = 0; i < 4; i++)
    {
        int curRow = row + dir[i];
        int curCol = col + dir[i + 1];
        //add connected 1 to this island.
        if (curRow >= 0 and curRow < A.size() and curCol >= 0 and curCol < A[0].size() and A[curRow][curCol] == 1)
        {
            DFS(A, dist, curRow, curCol);
        }
    }
}

//gives the minimum flips to connect the island out of all available ways.
int shortestPath(vector<vector<int>> &A, vector<vector<int>> &dist)
{
    int m = A.size();
    int n = A[0].size();
    int minimum{INT_MAX};
    while (!q.empty())
    {
        auto coord = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int curRow = coord.first + dir[i];
            int curCol = coord.second + dir[i + 1];
            int curDistance = dist[coord.first][coord.second] + 1;
            if (curRow >= 0 and curRow < m and curCol >= 0 and curCol < n and A[curRow][curCol] != -1)
            {
                if (curDistance < dist[curRow][curCol])
                { //if current node was 0 then make it 1 and store the number of flips done to make 1
                    dist[curRow][curCol] = curDistance;
                    q.push(make_pair(curRow, curCol));
                }

                //if we reach  an island then update minimum.
                if (A[curRow][curCol] == 1)
                {
                    minimum = min(minimum, dist[coord.first][coord.second]);
                }
            }
        }
    }

    return minimum;
}

int shortestBridge(vector<vector<int>> &A)
{
    if (A.empty())
        return 0;
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            { //finding the starting point of any island.
                DFS(A, dist, i, j);
                return shortestPath(A, dist);
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            //cout << x << endl;
        }
    }

    cout << shortestBridge(v) << endl;
}