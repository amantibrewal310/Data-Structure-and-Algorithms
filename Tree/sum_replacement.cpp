#include<bits/stdc++.h>
using namespace std;

/* Replace each node by "Sum of it's child nodes"
    Don't change leaf nodes
*/

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

int replaceSum(node* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL and root->right == NULL) {
        return root->data;
    }

    // Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + root->data;
}

void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* f = q.front();
        cout << f->data << " ";
        q.pop();
        if(f->left) {
            q.push(f->left);
        }
        if(f->right) {
            q.push(f->right);
        }
    }
    
}

signed main() {
    node* root = buildTree();
    bfs(root);
    cout << endl;
    replaceSum(root);
    bfs(root);
}