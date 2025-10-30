#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void sol(int arr[], int n) {
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    sol(arr, n);

    return 0;
}