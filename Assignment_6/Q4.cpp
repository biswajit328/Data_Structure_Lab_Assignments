#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next, *prev;
    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
    Node *head;

public:
    DLL() { head = NULL; }

    void insertAtHead(char x) {
        Node *newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (!head)
            return true; 
        if (!head->next)
            return true;

        Node *front = head;
        Node *end = head;
        while (end->next)
            end = end->next;

        while (front != end && front->prev != end) {
            if (tolower(front->data) != tolower(end->data))
                return false;
            front = front->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DLL d1;
    d1.insertAtHead('L');
    d1.insertAtHead('E');
    d1.insertAtHead('V');
    d1.insertAtHead('E');
    d1.insertAtHead('l');

    cout << "Doubly Linked List: ";
    d1.display();

    if (d1.isPalindrome())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
