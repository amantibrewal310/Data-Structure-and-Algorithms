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

int count(node* root) {
    if(root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

signed main() {
    node* root = buildTree();
    cout << count(root) << endl;

}