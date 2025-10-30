#include <iostream>
using namespace std;
#define MAX 5

int q1[MAX], q2[MAX];
int f1=-1, r1=-1, f2=-1, r2=-1;

bool isempty_q(int f,int r){
    return (f==-1 || f>r);
}

bool isfull(int r){
    return r==MAX-1;
}

void enqueue(int q[], int &f, int &r, int x){
    if(isfull(r)){
        cout << "Queue overflow\n";
        return;
    }
    if(f==-1) f=0;
    q[++r] = x;
}

int dequeue(int q[], int &f, int &r){
    if(isempty_q(f,r)){
        cout << "Queue underflow\n";
        return -1;
    }
    int val = q[f++];
    if(f>r) f=r=-1;
    return val;
}

void push(int x){
    enqueue(q2, f2, r2, x);              
    while(!isempty_q(f1,r1))             
        enqueue(q2, f2, r2, dequeue(q1,f1,r1));
    
    swap(q1, q2);
    swap(f1, f2);
    swap(r1, r2);
}

void pop(){
    if(isempty_q(f1,r1)){
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped element: " << dequeue(q1,f1,r1) << endl;
}

void top(){
    if(isempty_q(f1,r1)){
        cout << "Stack Empty\n";
        return;
    }
    cout << "Top element: " << q1[f1] << endl;
}

void display(){
    if(isempty_q(f1,r1)){
        cout << "Stack Empty\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for(int i=f1; i<=r1; i++)
        cout << q1[i] << " ";
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
    return 0;
}
