#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *next, *prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
    DNode *head;

public:
    DLL() { head = NULL; }

    void insertAtHead(int x) {
        DNode *newNode = new DNode(x);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    int size() {
        int count = 0;
        DNode *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode *next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CLL {
    CNode *head;

public:
    CLL() { head = NULL; }

    void insertAtHead(int x) {
        CNode *newNode = new CNode(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    int size() {
        if (!head)
            return 0;
        int count = 0;
        CNode *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        CNode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CLL c1;
    c1.insertAtHead(80);
    c1.insertAtHead(60);
    c1.insertAtHead(40);
    c1.insertAtHead(100);
    c1.insertAtHead(20);
    cout << "Circular Linked List: ";
    c1.display();
    cout << "Size of circular list is " << c1.size() << endl;

    DLL d1;
    d1.insertAtHead(50);
    d1.insertAtHead(40);
    d1.insertAtHead(30);
    d1.insertAtHead(20);
    d1.insertAtHead(10);
    cout << "\nDoubly Linked List: ";
    d1.display();
    cout << "Size of doubly list is " << d1.size() << endl;

    return 0;
}
