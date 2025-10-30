#include <iostream>
using namespace std;

#define MAX 100
int st[MAX];
int top = -1;
int minElement;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    if (isEmpty()) {
        st[++top] = x;
        minElement = x;
    } 
    else if (x >= minElement) {
        st[++top] = x;
    } 
    else {
        st[++top] = 2 * x - minElement;
        minElement = x;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    int t = st[top--];
    if (t < minElement) {
        minElement = 2 * minElement - t;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    int t = st[top];
    return (t >= minElement) ? t : minElement;
}

int getMin() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minElement;
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);

    cout << "Current Min: " << getMin() << endl;
    pop();
    cout << "Current Min: " << getMin() << endl;
    pop();
    cout << "Top: " << peek() << endl;
    cout << "Current Min: " << getMin() << endl;

}
