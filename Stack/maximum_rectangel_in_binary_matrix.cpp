#include<bits/stdc++.h>
using namespace std;

int maximumAreaHistogram(vector<int> &heights) {
    int n = heights.size();
    vector<int> right, left;
    int ans = 0;
    stack<int> s;
    
    for(int i = n - 1; i >= 0; i--) {
        if(s.size() == 0)
            right.push_back(n);
        else if(heights[s.top()] < heights[i])
            right.push_back(s.top());
        else {
            while(s.size() != 0 and heights[s.top()] >= heights[i])
                s.pop();
            if(s.size() == 0)
                right.push_back(n);
            else
                right.push_back(s.top());
        }
        s.push(i);
    }
    reverse(right.begin(), right.end());
    
    while(s.size() > 0) s.pop();
    
    for(int i = 0; i < n; i++) {
        if(s.size() == 0)
            left.push_back(-1);
        else if(heights[s.top()] < heights[i])
            left.push_back(s.top());
        else {
            while(s.size() != 0 and heights[s.top()] >= heights[i])
                s.pop();
            if(s.size() == 0)
                left.push_back(-1);
            else
                left.push_back(s.top());
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++) {
        int area = (right[i] - left[i] - 1) * heights[i];
        // cout << right[i] << " " << left[i] << endl;
        ans = max(ans, area);
    }
    return ans;
    
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    vector<int> heights;
    for(int i = 0; i < matrix[0].size(); i++) {
        heights.push_back(matrix[0][i] - '0');
    }
    int ans = maximumAreaHistogram(heights);
    cout << ans << endl;
    
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] == '0')
                heights[j] = 0;
            else 
                heights[j] += (matrix[i][j] - '0');
        }
        int area = maximumAreaHistogram(heights);
        ans = max(ans, area);
    }
    return ans;
    
}

signed main() {
    int n;
    cin >> n;
    vector<vector<char>> matrix;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    cout << maximalRectangle(matrix) << endl;
}