#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CLL {
    Node *head;

public:
    CLL() { head = NULL; }

    void insertAtHead(int x) {
        Node *newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void display() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    bool isCircular() {
        if (!head)
            return false;
        Node *temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    CLL c1;
    c1.insertAtHead(80);
    c1.insertAtHead(60);
    c1.insertAtHead(40);
    c1.insertAtHead(100);
    c1.insertAtHead(20);

    cout << "Linked List: ";
    c1.display();

    if (c1.isCircular())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
