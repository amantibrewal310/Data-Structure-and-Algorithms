#include <bits/stdc++.h>
using namespace std;

struct Node {
  char c;
  vector<Node*> children;
  bool isTerminal;
  Node() {
    children.assign(26, NULL);
    c = '#';
    isTerminal = false;
  }
  Node(char c) {
    this->c = c;
    isTerminal = false;
    children.assign(26, NULL);
  }
};

void dfs(Node* root, vector<string>& res, string& search) {
  if (res.size() == 3) return;
  if (root->isTerminal) {
    res.push_back(search);
  }
  for (int i = 0; i < 26; i++) {
    if (root->children[i]) {
      search += ('a' + i);
      dfs(root->children[i], res, search);
      search.pop_back();
    }
  }
}

class Trie {
  Node* root;

 public:
  Trie() { root = new Node(); }

  void insert(string s) {
    Node* temp = root;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (temp->children[ch - 'a']) {
        temp = temp->children[ch - 'a'];
      } else {
        Node* n = new Node(ch);
        temp->children[ch - 'a'] = n;
        temp = n;
      }
    }
    temp->isTerminal = true;
  }
  bool find(string s) {
    Node* temp = root;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (!temp->children[ch - 'a']) return false;
      temp = temp->children[ch - 'a'];
    }
    return temp->isTerminal;
  }
  vector<string> search(string s) {
    Node* temp = root;
    string t = "";
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (!temp->children[ch - 'a']) return {};
      temp = temp->children[ch - 'a'];
      t += ch;
    }
    vector<string> res;
    dfs(temp, res, t);
    return res;
  }
};

signed main() {
  int n;
  cin >> n;
  vector<string> products(n);
  Trie t;

  for (auto product : products) {
    cin >> product;
    t.insert(product);
  }
  string search;
  cin >> search;

  vector<vector<string>> ans;

  for (int i = 0; i < search.length(); i++) {
    string word = search.substr(0, i + 1);
    vector<string> tmp = t.search(word);
    ans.push_back(tmp);
  }
  for (int i = 0; i < ans.size(); i++) {
    for (auto word : ans[i]) {
      cout << word << " ";
    }
    cout << endl;
  }
}