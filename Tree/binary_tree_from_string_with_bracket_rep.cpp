//?https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) { this->val = val; }
};

TreeNode* dfs(string s) {
  if (s.length() == 0) return NULL;
  TreeNode* root = new TreeNode(s[0] - '0');
  int n = s.length();
  if (n == 1) return root;
  string left = "", right = "";
  int sum = 0;
  int i = 1;
  while (i < n) {
    if (s[i] == '(') {
      sum += 1;
    } else if (s[i] == ')') {
      sum -= 1;
    }
    if (sum == 0) {
      break;
    }
    i++;
  }
  left = s.substr(1, i - 1 + 1);
  sum = 0;
  int j = i;
  i++;
  while (i < n) {
    if (s[i] == '(') {
      sum += 1;
    } else if (s[i] == ')') {
      sum -= 1;
    }
    if (sum == 0) break;
    i++;
  }
  right = s.substr(j + 1, i - j);
  cout << left << endl;
  cout << right << endl;
  if (left.length() > 2) {
    root->left = dfs(left.substr(1, left.length() - 2));
  }
  if (right.length() > 2) {
    root->right = dfs(right.substr(1, right.length() - 2));
  }
  return root;
}

void print(TreeNode* root) {
  if (!root) return;
  cout << root->val << endl;
  print(root->left);
  print(root->right);
}

signed main() {
  string s;
  cin >> s;

  TreeNode* root = dfs(s);

  print(root);
}