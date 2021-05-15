//?https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
  char c;
  int freq;
  Node* left;
  Node* right;

  Node(char c, int freq) {
    this->c = c;
    this->freq = freq;
    this->left = NULL;
    this->right = NULL;
  }
};

struct cmp {
  bool operator()(Node* left, Node* right) {
    return (left->freq > right->freq);
  }
};

void print(Node* root, string s) {
  if (!root) return;
  if (root->c != '#') {
    cout << root->c << " " << s << endl;
  }
  print(root->left, s + '0');
  print(root->right, s + '1');
}

signed main() {
  string s;
  cin >> s;
  unordered_map<char, int> freq;

  for (char c : s) {
    freq[c]++;
  }
  priority_queue<Node*, vector<Node*>, cmp> pq;

  for (auto p : freq) {
    char c = p.first;
    int cnt = p.second;

    Node* tmp = new Node(c, cnt);
    pq.push(tmp);
  }

  while (pq.size() > 1) {
    Node* left = pq.top();
    pq.pop();
    Node* right = pq.top();
    pq.pop();
    int cnt = left->freq + right->freq;
    Node* tmp = new Node('#', cnt);
    tmp->left = left;
    tmp->right = right;
    pq.push(tmp);
  }

  print(pq.top(), "");
}