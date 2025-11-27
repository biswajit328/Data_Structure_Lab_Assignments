#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a new node at tail
void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Function to add two linked lists (numbers)
Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if (first != NULL) val1 = first->data;

        int val2 = 0;
        if (second != NULL) val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        // insert digit at tail of answer list
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL) first = first->next;
        if (second != NULL) second = second->next;
    }
    return ansHead;
}

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to add two numbers represented by linked lists
Node* addTwo(Node* first, Node* second) {
    // Step 1: reverse both lists
    first = reverse(first);
    second = reverse(second);

    // Step 2: perform addition
    Node* ans = add(first, second);

    // Step 3: reverse the final answer
    ans = reverse(ans);
    return ans;
}

// Helper to print a linked list
void print(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: First number = 3->4->5 (represents 345)
    //          Second number = 4->5 (represents 45)
    Node* first = new Node(3);
    first->next = new Node(4);
    first->next->next = new Node(5);

    Node* second = new Node(4);
    second->next = new Node(5);

    Node* result = addTwo(first, second);
    cout << "Result: ";
    print(result);

    return 0;
}