#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
};

node *head = NULL;

void inserAtHead(int data) {
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

int length() {
    int len = 0;
    node *p = head;
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

void insertAtTail(int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(int data, int pos) {
    if(head == NULL or pos ==0) {
        inserAtHead(data);
    } else if(pos > length()) {
        insertAtTail(data);
    } else {
        int jump = 1;
        node *temp = head;
        while(jump < pos - 1) {
            jump += 1;
            temp = temp->next;
        }

        node *p = new node(data);
        p->next = temp->next;
        temp->next = p;
    }

}

void print() {
    node *p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteAtHead() {
    if(head == NULL) {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail() {
    node *prev = NULL;
    node *temp = head;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    delete temp;
    prev->next = NULL;
    return;
}

void deleteInMiddle(int pos) {
    if(head == NULL)
        return;
    if(head->next == NULL) {
        delete head;
        return;
    }
    if(pos == 1) {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int jump = 0;
    node *prev = NULL;
    node *temp = head;
    while(jump < pos - 1) {
        jump++;
        prev = temp;
        temp = temp->next;
    }
    cout << jump << endl;
    prev->next = temp->next;
    delete temp;
    return;
}

bool searchRecursive(node *head, int key) {
    if(head == NULL) {
        return false;
    }
    if(head->val == key) {
        return true;
    } else {
        return searchRecursive(head->next, key);
    }
}
bool searchIterative(int key) {
    node *p = head;
    while(p != NULL) {
        if(p->val == key)
            return true;
        p = p->next;
    }
    return false;
}

void buildList() {
    int data;
    cin >> data;
    while(data != -1) {
        insertAtTail(data);
        cin >> data;
    }
}
istream& operator>>(istream &is, node *&head) {
    buildList();
    return is;
}

ostream& operator<<(ostream &os, node *head) {
    print();
    return os;
}

signed main () {
    // buildList();

    // print();
    // insertInMiddle(6, 2);
    // print();

    // deleteAtHead();
    // deleteAtTail();
    // print();
    // deleteInMiddle(1);
    // print();

    // cout << searchRecursive(head, 3) << endl;
    // cout << searchIterative(5) << endl;
    cin >> head;
    cout << head;


}