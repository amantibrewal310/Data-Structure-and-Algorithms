#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int findIndex(vector<int> &inorder, int start, int end, int key) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == key)
            return i;
    }
    return -1;
}

TreeNode* helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
    if(inStart > inEnd or postStart > postEnd) 
        return NULL;
    
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);

    int leftTreeSize = rootIndex - inStart;
    int rightTreeSize = inEnd - rootIndex;

    root->left = helper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftTreeSize - 1);

    root->right = helper(inorder, rootIndex + 1, inEnd, postorder, postEnd - rightTreeSize, postEnd - 1);
    return root;
}


TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
    int n = inorder.size();
    if(n == 0)
        return NULL;
    return helper(inorder, 0, n - 1, postorder, 0, n - 1);
}

vector<vector<int>> bfs(TreeNode* root) {
    if(root == NULL)
        return {};
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    vector<vector<int>> ans;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(p.second + 1 > ans.size())
            ans.push_back({p.first->val});
        else
            ans[p.second].push_back(p.first->val);
        
        if(p.first->left)
            q.push({p.first->left, p.second + 1});
        if(p.first->right) 
            q.push({p.first->right, p.second + 1});
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for(auto &x : inorder) {
        cin >> x;
    } 
    for(auto &x : postorder) {
        cin >> x;
    }

    TreeNode* root = buildTree(inorder, postorder);
    auto res = bfs(root);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}