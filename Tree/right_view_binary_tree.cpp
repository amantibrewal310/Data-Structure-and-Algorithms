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

void printRightView(node* root, int level, int &maxLevel) {
    if(root == NULL)
        return;
    if(maxLevel < level) {
        cout << root->data << " ";
        maxLevel = level;
    }
    // right
    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

signed main() {
    node* root = buildTree();
    int maxLevel = -1;
    printRightView(root, 0, maxLevel);

}