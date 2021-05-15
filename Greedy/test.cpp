class Solution {
  vector<string> ans;

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
      ans.push_back(s);
    }
    print(root->left, s + '0');
    print(root->right, s + '1');
  }

 public:
  vector<string> huffmanCodes(string S, vector<int> f, int N) {
    // Code here
    ans.clear();
    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < N; i++) {
      char c = S[i];
      int cnt = f[i];

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
  return ans;
};