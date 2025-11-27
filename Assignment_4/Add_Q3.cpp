#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front(); q.pop();
        if (front == expected)
            expected++;
        else {
            if (!st.empty() && st.top() < front)
                return false;
            st.push(front);
        }
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }
    return expected - 1 == n;
}

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);
    if (checkSorted(q)) cout << "Yes";
    else cout << "No";
}