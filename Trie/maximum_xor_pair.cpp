#include<bits/stdc++.h>
using namespace std;

/*
    !Problem - Max Xor Pair
    Find a pair with maximum xor

    Input[] = {3, 10, 5, 25, 2, 8};
    output[] = 5 ^ 25 = 28;
*/
class Node {
    public:
        Node* left; // for 0
        Node* right; // for 1
};

class Trie {
    Node* root;
    
    public:
        Trie() {
            root = new Node();
        }

        // Insert Function
        //  5 = 00000101 [32 bit integer]

        void insert(int n) {
            Node* temp = root;
            // loop
            for(int i = 31; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if(bit == 0) {
                    if(temp->left == NULL) {
                        temp->left = new Node();
                    }
                    temp = temp->left;
                } else {
                    // bit is 1
                    if(temp->right == NULL)
                        temp->right = new Node();
                    temp = temp->right;
                }
            }
        }

        // helper function to find max xor
        int maxXorHelper(int value) {
            Node* temp = root;
            int curren_ans = 0;
            for(int j = 31; j >= 0; j--) {
                int bit = (value >> j) & 1;

                if(bit == 0) {
                    // find a complementary value
                    if(temp->right != NULL) {
                        temp = temp->right;
                        curren_ans += (1 << j);
                    } else {
                        temp = temp->left;
                    }
                } else {
                    // current bit is 1
                    if(temp->left != NULL) {
                        temp = temp->left;
                        curren_ans += (1 << j);
                    } else {
                        temp = temp->right;
                    }
                }
            }
            return curren_ans;
        }

        int maxXor(vector<int> input) {
            int maxXor = 0;

            for(int i = 0; i < input.size(); i++) {
                int val = input[i];
                insert(val);
                int current_xor = maxXorHelper(val);

                maxXor = max(current_xor, maxXor);
            }
            return maxXor;
        }
};

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    Trie t;
    for(auto &x : v)
        cin >> x;
    cout << t.maxXor(v) << endl;

}