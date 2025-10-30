#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *next, *prev;
    DNode(int val) { data = val; next = prev = NULL; }
};

class DoublyLinkedList {
    DNode *head = NULL;
public:
    void insertAtHead(int val) {
        DNode *n = new DNode(val);
        if (!head) { head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAtEnd(int val) {
        DNode *n = new DNode(val);
        if (!head) { head = n; return; }
        DNode *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found!\n"; return; }
        DNode *n = new DNode(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void display() {
        cout << "Doubly List: ";
        for (DNode *t = head; t; t = t->next) cout << t->data << " ";
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode *next;
    CNode(int val) { data = val; next = NULL; }
};

class CircularLinkedList {
    CNode *last = NULL;
public:
    void insertAtHead(int val) {
        CNode *n = new CNode(val);
        if (!last) { last = n; n->next = n; return; }
        n->next = last->next;
        last->next = n;
    }

    void insertAtEnd(int val) {
        CNode *n = new CNode(val);
        if (!last) { last = n; n->next = n; return; }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    void insertAfter(int key, int val) {
        if (!last) { cout << "Empty list\n"; return; }
        CNode *temp = last->next;
        do {
            if (temp->data == key) {
                CNode *n = new CNode(val);
                n->next = temp->next;
                temp->next = n;
                if (temp == last) last = n;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Key not found!\n";
    }

    void display() {
        if (!last) { cout << "Circular List Empty\n"; return; }
        cout << "Circular List: ";
        CNode *t = last->next;
        do { cout << t->data << " "; t = t->next; } while (t != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insertAtHead(10);
    dll.insertAtEnd(20);
    dll.insertAfter(10, 15);
    dll.display();

    cll.insertAtHead(30);
    cll.insertAtEnd(40);
    cll.insertAfter(30, 35);
    cll.display();
}
