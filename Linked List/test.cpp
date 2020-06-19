#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

signed main() {
    node* temp = new node();
    temp->data = 2;
    temp->next = NULL;
    cout << temp->data << endl;
    cout << temp << endl;
}