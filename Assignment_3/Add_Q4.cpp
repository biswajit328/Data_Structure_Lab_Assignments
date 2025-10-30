#include <iostream>
using namespace std;

#define MAX 1000

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[MAX], answer[MAX];
    for(int i = 0; i < n; i++) {
        cin >> temperatures[i];
        answer[i] = 0; 
    }

    int stack[MAX], top = -1;

    for(int i = 0; i < n; i++) {
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            
            answer[stack[top]] = i - stack[top];
            top--;
        }
        stack[++top] = i; 
    }

    cout << "Answer: ";
    for(int i = 0; i < n; i++) cout << answer[i] << " ";
    cout << endl;

    return 0;
}