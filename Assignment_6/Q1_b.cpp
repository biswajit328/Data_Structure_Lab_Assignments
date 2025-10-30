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

    void deleteNode(int key) {
        DNode *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        if (temp == head) head = head->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
        cout << "Deleted " << key << endl;
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

    void deleteNode(int key) {
        if (!last) { cout << "List empty\n"; return; }
        CNode *curr = last->next, *prev = last;
        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) last = NULL;
                else { prev->next = curr->next; if (curr == last) last = prev; }
                delete curr;
                cout << "Deleted " << key << endl;
                return;
            }
            prev = curr; curr = curr->next;
        } while (curr != last->next);
        cout << "Node not found!\n";
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
    dll.deleteNode(20);
    dll.display();

    cll.insertAtEnd(40); cll.insertAtEnd(50); cll.insertAtEnd(60);
    cll.display();
    cll.deleteNode(50);
    cll.display();
}
