#include<bits/stdc++.h>
using namespace std;
#define int long long

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

node* insertInBST(node* root, int data) {
    if(root == NULL) {
        return new node(data);
    }
    if(root->data > data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node* buildBST() {
    int data;
    cin >> data;
    node *root = NULL;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}

class LinkedList{
    public:
        node* head;
        node* tail;
};

LinkedList flatten(node* root) {
    LinkedList l;

    if(root == NULL) {
        l.head = l.tail = NULL;
        return l;
    }
    // leaf Node
    if(root->left == NULL and root->right == NULL) {
        l.head = l.tail = root;
        return l;
    }
    // Left is not NULL
    if(root->left != NULL and root->right == NULL) {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // Right is not NULL
    if(root->left == NULL and root->right != NULL) {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    // Both sides are not NULL
    LinkedList leftLL =  flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.tail;
    return l;
}

signed main() {
    
}