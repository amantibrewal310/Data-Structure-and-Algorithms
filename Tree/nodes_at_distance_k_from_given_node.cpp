#include<bits/stdc++.h>
using namespace std;
/*
    ?Binary Tree Nodes at K distance from given Target Node
*/

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

void printAtLevelK(node* root, int k) {
    if(root == NULL)
        return;
    if(k == 0)
        cout << root->data << " ";
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

int printAtDistanceK(node* root, node* target, int k) {
    //base case
    if(root == NULL)
        return -1;

    // reach the target node
    if(root == target) {
        printAtLevelK(target, k);
        return 0;
    }

    // next step back to ancestor
    int DL = printAtDistanceK(root->left, target, k);
    if(DL != -1) {
        // Again there are 2 cases
        // Ancestor itself or you need go to the right ancestor

        if(DL + 1 == k)
            cout << root->data << " ";
        else 
            printAtLevelK(root->right, k - DL - 2);
        
        return 1 + DL;
    }

    int DR = printAtDistanceK(root->right, target, k);

    if(DR != -1) {
        if(DR + 1 == k)
            cout << root->data << " ";
        else 
            printAtLevelK(root->left, k - 2 - DR);
        return 1 + DR;
    }
    //NOde was not present in left and right subtree
    return -1;


}

signed main() {
    node* root = buildTree();
    node* target = root->left->left;
    printAtDistanceK(root, target, 3);
    
}