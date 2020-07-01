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

class Pair {
    public:
        int branchSum;
        int maxSum;
        Pair() {
            branchSum = 0;
            maxSum = 0;
        }
};

Pair maxSumPath(node* root) {
    Pair p;

    if(root == NULL) {
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // construct two values
    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = left.branchSum + root->data + right.branchSum;

    int curr_ans_through_root = max({op1, op2, op3, op4});

    // branch sum of the current root

    p.branchSum = max({left.branchSum, right.branchSum, 0}) + root->data;
    p.maxSum = max({left.maxSum, right.maxSum, curr_ans_through_root});

    return p;
}

signed main() {
    node* root = buildTree();

    cout << maxSumPath(root).maxSum << endl;
     
}