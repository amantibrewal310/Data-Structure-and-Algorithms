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

// Accepts the old root node and data and returns the new root node
node* insertInBST(node* root, int data) {
    // Base Case
    if(root == NULL)
        return new node(data);
    // recursive case
    if(data <= root->data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        cout << f->data << " ";
        q.pop();

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return;
}

node* buildBST() {
    // Read a list of numbers till -1 and also these numbers will be inserted into BST

    int data;
    cin >> data;
    node* root = NULL;
    while(data != -1) {
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}

void inorder(node* root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(node* root, int key) {
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    else if(root->data > key)
        return search(root->left, key);
    return search(root->right, key);
}

node* deleteInBST(node* root, int key) {
    if(root == NULL)
        return NULL;
    else if(root->data == key) {
        // 3 cases
        // Case 1 : 0 childeren case
        if(root->left == NULL and root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2 : 1 child
        else if(root->left == NULL and root->right != NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if(root->left != NULL and root->right == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3 : 2 Children case
        if(root->left != NULL and root->right != NULL) {
            // Inorder Successor 
            node* replace = root->right;

            while(replace->left != NULL) {
                replace = replace->left;
            }

            root->data = replace->data;
            root->right = deleteInBST(root->right, replace->data);

            return root;
        }
    } else if(root->data > key) {
        root->left = deleteInBST(root->left, key);
    } else {
        root->right = deleteInBST(root->right, key);
    }

    return root;
}

signed main() {

    node* root = buildBST();
    inorder(root);
    root = deleteInBST(root, 5);
    cout << endl;
    inorder(root);
}