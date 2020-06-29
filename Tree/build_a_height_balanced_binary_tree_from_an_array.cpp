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
node* buildTreeFromArray(vector<int> a, int start, int end) {
    if(start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, start, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, end);
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
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    node* root = buildTreeFromArray(a, 0, n - 1);
    bfs(root);
}