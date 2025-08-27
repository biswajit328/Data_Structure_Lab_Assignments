#include <iostream>
using namespace std;
#define max 10
char stack[max];
int top = -1;

bool isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(int n)
{
        top++;
        stack[top] = n;
}

char pop(){
    if(isempty()) return '\0';
    else {
        return stack[top--];
    }
}

string reverse(string &str){

    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str[i] = pop();
    }
    return str;
}

int main(){

string a = "DataStructure"; 
cout<<reverse(a);

}