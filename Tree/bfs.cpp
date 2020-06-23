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

node* buildTree() {
    int data;
    cin >> data;
    if(data == -1)
        return NULL;
    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfs(node* root) {
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* f = q.front();
        cout << f->data << " ";
        q.pop();

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return;
    
}

signed main() {

    node* root = buildTree();
    bfs(root);

}