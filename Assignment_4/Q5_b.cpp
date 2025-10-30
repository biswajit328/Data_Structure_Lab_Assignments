#include <iostream>
using namespace std;
#define MAX 10

int q[MAX];
int front = -1, rear = -1;

bool isempty(){
    return (front == -1 || front > rear);
}

bool isfull(){
    return rear == MAX - 1;
}

void enqueue(int x){
    if(isfull()){
        cout << "Queue overflow\n";
        return;
    }
    if(front == -1) front = 0;
    q[++rear] = x;
}

int dequeue(){
    if(isempty()){
        cout << "Queue underflow\n";
        return -1;
    }
    int val = q[front++];
    if(front > rear) front = rear = -1;
    return val;
}

void push(int x){
    int count = (isempty() ? 0 : rear - front + 1);
    enqueue(x);
    for(int i = 0; i < count; i++)
        enqueue(dequeue());
}

void pop(){
    if(isempty()){
        cout << "Stack underflow\n";
        return;
    }
    cout << "Popped: " << dequeue() << endl;
}

void top(){
    if(isempty()){
        cout << "Stack empty\n";
        return;
    }
    cout << "Top element: " << q[front] << endl;
}

void display(){
    if(isempty()){
        cout << "Stack empty\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);

    display();   
    top();       

    pop();      
    display();  
    top();       
    return 0;
}
