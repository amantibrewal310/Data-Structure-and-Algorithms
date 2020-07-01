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

int search(node* root, int key, int level) {
    if(root == NULL)
        return -1;
    if(root->data == key)
        return level;
    
    int left = search(root->left, key, level + 1);
    if (left != -1)
        return left;
    return search(root->right, key, level + 1);    
}

node* lca(node* root, int a, int b) {
    if(root == NULL)
        return NULL;

    if(root->data == a or root->data == b)
        return root;
    
    node* leftans = lca(root->left, a, b);
    node* rightans = lca(root->right, a, b);

    if(leftans != NULL and rightans != NULL)
        return root;
    
    if(leftans != NULL)
        return leftans;
    
    return rightans;
}

int findDistance(node* root, int a, int b) {
    node* lca_node = lca(root, a, b);
    // cout << lca_node->data << endl;

    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);

    return l1 + l2;
}

void printInorder(node*root) {
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << endl;
    printInorder(root->right);
}

signed main() {

    node* root = buildTree();
    // printInorder(root);
    cout << "Enter the two nodes" << endl;
    int a, b;
    cin >> a >> b;
    cout << findDistance(root, a, b) << endl;

}