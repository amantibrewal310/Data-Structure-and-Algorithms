#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    queue<TreeNode*> q;

    q.push(B);
    

    while(q.size() > 0) {
        int size = q.size();
        while(size--) {
            auto node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }

            if(parent[node]) {
                q.push(parent[node]);
            }
        }
        ans++;
    }
    return ans;
}