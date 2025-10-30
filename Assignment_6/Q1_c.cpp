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
    void insertAtEnd(int val) {
        DNode *n = new DNode(val);
        if (!head) { head = n; return; }
        DNode *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n; n->prev = temp;
    }

    void search(int key) {
        DNode *temp = head;
        while (temp) {
            if (temp->data == key) { cout << "Found " << key << endl; return; }
            temp = temp->next;
        }
        cout << "Not Found\n";
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
    void insertAtEnd(int val) {
        CNode *n = new CNode(val);
        if (!last) { last = n; n->next = n; return; }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    void search(int key) {
        if (!last) { cout << "Empty list\n"; return; }
        CNode *t = last->next;
        do {
            if (t->data == key) { cout << "Found " << key << endl; return; }
            t = t->next;
        } while (t != last->next);
        cout << "Not Found\n";
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

    dll.insertAtEnd(10); dll.insertAtEnd(20); dll.insertAtEnd(30);
    dll.display();
    dll.search(20);
    dll.search(40);

    cll.insertAtEnd(50); cll.insertAtEnd(60); cll.insertAtEnd(70);
    cll.display();
    cll.search(60);
    cll.search(90);
}
