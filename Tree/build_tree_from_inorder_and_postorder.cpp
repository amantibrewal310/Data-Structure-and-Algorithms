#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* createTreeFromTrav(vector<int> pre, vector<int> in, int start, int end) {
    // Here start and end variable will be use for inorder array;

    static int i = 0; // for preorder traversal node
    
    // base case
    if(start > end)
        return NULL;
    
    node *root = new node(pre[i]);

    int idx = -1;
    for(int j = start; j <= end; j++) {
        if(in[j] == pre[i]) {
            idx = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(pre, in, start, idx - 1);
    root->right = createTreeFromTrav(pre, in, idx + 1, end);
    return root;
}

void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* f = q.front();
        cout << f->data << " ";
        q.pop();
        if(f->left)
            q.push(f->left);
        if(f->right)
            q.push(f->right);
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> pre(n); // Preorder array
    for(int &x : pre)
        cin >> x;
    vector<int> in(n); // Inorder array
    for(int &x : in)
        cin >> x;
    node* root = createTreeFromTrav(pre, in, 0, n - 1);
    bfs(root);
}