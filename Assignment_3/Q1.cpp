#include <iostream>
using namespace std;
#define max 6

int stack[max];
int top = -1;

bool isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void pop()
{
    if (isempty())
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        cout << stack[top] << " poped" << endl;
        top--;
    }
}

void push(int n)
{
        top++;
        stack[top] = n;
}

bool isfull(){
    if(top==max) return true;
    else return false;
}

void peek(){
    cout<<stack[top]<<endl;
}

void display(){
    for (int i = 0; i <= top; i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    cout<<isempty()<<endl;

    cout<<isfull()<<endl;

    display();

    peek();

    pop();

    display();


}