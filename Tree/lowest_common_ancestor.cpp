#include<bits/stdc++.h>
using namespace std;

struct node{
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

// assumption both a and b are present in the tree, all keys are unique

node* lca(node*root, int a, int b) {
    if(root == NULL)
        return NULL;
    if(root->data == a or root->data == b)
        return root;
    
    //serach in left and right subtrees
    node* leftans = lca(root->left, a, b);
    node* rightans = lca(root->right, a, b);

    if(leftans != NULL and rightans != NULL)
        return root;
    if(leftans != NULL)
        return leftans;
    return rightans;
    
}

signed main() {
    node* root = buildTree();

}