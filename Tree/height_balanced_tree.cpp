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
    if(data == -1) {
        return NULL;
    }
    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node* root) {
    if(root == NULL)
        return 0;
    
    return 1 + max(height(root->left), height(root->right));
}

bool checkBalanceTree(node* root) {
    if(root == NULL)
        return true;
    if(checkBalanceTree(root->left) and checkBalanceTree(root->right)) {
        int h1 = height(root->left);
        int h2 = height(root->right);
        if (abs(h1 - h2) <= 1)
            return true;
    }
    return false;
    
}

signed main() {
    node* root = buildTree();
    cout << checkBalanceTree(root) << endl;
}