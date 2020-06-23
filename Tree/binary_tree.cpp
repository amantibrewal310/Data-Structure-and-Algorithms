#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
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

int height(node* root) {
    if(root == NULL)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}
// Preorder Print
void preorderPrint(node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
     
}
// Inorder Print
void inorderPrint(node* root) {
    if(root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Postorder
void postorderPrint(node* root) {
    if(root == NULL)
        return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

// Level Order
void printKthLevel(node* root, int k) {
    if(root == NULL)
        return;
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

void levelorderPrint(node* root) {
    int h = height(root);
    for(int i = 1; i <=h; i++)
        printKthLevel(root, i);
}

signed main() {

    node* root = buildTree();
    preorderPrint(root);
    cout << endl;
    cout << height(root) << endl;
    // printKthLevel(root, 3);
    levelorderPrint(root);

}