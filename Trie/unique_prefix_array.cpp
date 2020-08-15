#include<bits/stdc++.h>
using namespace std;

/*
    !Problem - Unique Prefix Array

    words[] = ["cobra", "dog", "dove", "duck"]

    output[] = ["c", "dog", "dov", "du"]

*/
class Node {
    public:
        char data;
        int cnt;
        unordered_map<char, Node*> children;
        bool terminal;

        Node(char c) {
            data = c;
            cnt = 1;
            terminal = false;
        }
};

class Trie {
    Node* root;
    int cnt;
    public:
    Trie() {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(string s) {
        Node* temp = root;

        for(int i = 0; i < s.length(); i++) {
            if(temp->children.count(s[i])) {
                temp = temp->children[s[i]];
                temp->cnt++;
            }
            else {
                Node* n = new Node(s[i]);
                temp->children[s[i]] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    string findPrefix(string s) {
        Node* temp = root;
        string prefix = "";
        prefix += s[0];
        temp = temp->children[s[0]];
        for(int i = 1; i < s.length(); i++) {
            if(temp->cnt == 1)
                return prefix;
            temp = temp->children[s[i]];
            prefix += s[i];
        }
        return prefix;
    }
};

signed main() {
    int n;
    cin >> n;
    vector<string> s(n);
    Trie t;
    for(auto &x : s) {
        cin >> x;
        t.insert(x);
    }
    vector<string> ans;
    for(auto x : s) {
        ans.push_back(t.findPrefix(x));
    }
    for(auto x : ans) {
        cout << x << endl;
    }
    
}
