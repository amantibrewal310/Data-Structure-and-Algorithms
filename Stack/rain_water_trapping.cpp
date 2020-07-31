#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height) {
    int ans = 0, current = 0;
    stack<int> s;

    while(current < height.size()) {
        while(!s.empty() and height[current] > height[s.top()]) {
            int top = s.top();
            s.pop();
            if(s.empty())
                break;
            int distance = current - s.top() - 1;
            int boundedHeight = min(height[current], height[s.top()]) - height[top];
            ans += distance * boundedHeight;
            // cout << ans << endl;
        }
        s.push(current++);
    }
    return ans;
}


signed main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(auto &h : heights) {
        cin >> h;
    }
    
    cout << trap(heights) << endl;
}