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
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; 
    }

    int size() {
        if (!head)
            return 0;
        int count = 0;
        Node *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
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
    return 0;
}
