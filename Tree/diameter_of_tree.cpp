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
int height(node* root) {
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right))+ 1;
}

// Time complexity is O(n^2)
int diameter(node* root) {
    if(root == NULL)
        return 0;
    
    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max({op1, op2, op3});
}

// optimise diameter

struct Pair {
    int height;
    int diameter;
};

Pair fastDiameter(node* root) {
    Pair p;
    if(root == NULL) {
        p.diameter = p.height = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

signed main() {


    node* root = buildTree();
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    // cout << diameter(root) << endl;
    Pair p = fastDiameter(root);

    cout << p.height << endl;
    cout << p.diameter << endl;

}