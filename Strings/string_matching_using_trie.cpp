#include<bits/stdc++.h>
using namespace std;

struct Trie {
    Trie *nxt[26];
    bool ended;

    Trie() {
        for(int i = 0; i < 26; i++) {
            nxt[i] = NULL;
        }
        ended = false;
    }
};

Trie *root;

void insert(string s) {
    Trie *curr = root;

    for(int i = 0; i < s.length(); i++) {
        if(curr->nxt[s[i] - 'a'] == NULL) {
            curr->nxt[s[i] - 'a'] = new Trie();
        }
        curr = curr->nxt[s[i] - 'a'];
    }
    curr->ended = true;
}

bool inTrie(string s) {
    Trie *curr = root;

    for(int i = 0; i < s.length(); i++) {
        if(curr->nxt[s[i] - 'a'] == NULL)
            return false;
        curr = curr->nxt[s[i] - 'a'];
    }
    return true;
}

signed main() {
    string text = "abaacadbacad";
    string pat = "aaca";

    int n = text.size(), m = pat.size();
    root = new Trie();

    //construct Trie

    for(int i = 0; i < n; i++) {
        insert(text.substr(i));
    }

    if(inTrie(pat)) {
        cout << "Yes Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }


}