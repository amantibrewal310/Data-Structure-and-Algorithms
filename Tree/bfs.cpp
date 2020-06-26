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
void bfs2(node* root) {
    queue<pair<node*, int>> q;
    int k = 1;
    q.push(make_pair(root, k));
    int prevLevel = 1;
    while(!q.empty()) {
        pair<node*, int> f = q.front();
        if (prevLevel != f.second)
        {
            cout << endl;
            prevLevel = f.second;
        }
        cout << f.first->data << " ";
        
        q.pop();

        if(f.first->left) {
            q.push(make_pair(f.first->left, f.second + 1));
        }
        if(f.first->right) {
            q.push(make_pair(f.first->right, f.second + 1));
        }
    }
    return;
}

signed main() {

    node* root = buildTree();
    bfs(root);
    cout << endl;
    bfs2(root);

}