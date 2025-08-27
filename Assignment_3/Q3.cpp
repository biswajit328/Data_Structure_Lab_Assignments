#include <iostream>
using namespace std;
#define max 30
char stack[max];
int top = -1;

bool isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void push(char n)
{
    top++;
    stack[top] = n;
}

char pop()
{
    if (isempty())
        return '\0';
    else
    {
        return stack[top--];
    }
}

bool balanced_parentheses(string str)
{
    top = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }

        else if ((str[i] == ')' || str[i] == ']' || str[i] == '}'))
        {
            if (isempty())
                return false;
            char c = pop();
            if (!((c == '(' && str[i] == ')') || (c == '[' && str[i] == ']') || (c == '{' && str[i] == '}')))
                return false;
        }
    }
    return (isempty());
}

int main()
{

    string s1 = "{(a+b)*[c/(d-e)]}";
    string s2 = "a+{b*(c+d)";

    cout << balanced_parentheses(s1) << endl
         << balanced_parentheses(s2) << endl;
}