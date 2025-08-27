#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];        
        if (isdigit(ch)) {
            st.push(ch - '0');   
        }
        else {
            
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main() {
    string expr1 = "231*+9-";  
    string expr2 = "34+2*";    

    cout << expr1 << " = " << evaluatePostfix(expr1) << endl;
    cout << expr2 << " = " << evaluatePostfix(expr2) << endl;

  
}