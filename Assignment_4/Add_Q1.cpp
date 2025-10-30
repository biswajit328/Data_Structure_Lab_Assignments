#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;

    q.push("1"); 

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << " are:\n";
    generateBinaryNumbers(n);

    cout << endl;
    return 0;
}
