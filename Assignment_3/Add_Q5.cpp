#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int n;
    int A[MAX], sortedA[MAX];
    int S[MAX], top = -1;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements of A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sortedA[i] = A[i]; 
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedA[j] > sortedA[j + 1]) {
                int temp = sortedA[j];
                sortedA[j] = sortedA[j + 1];
                sortedA[j + 1] = temp;
            }
        }
    }

    int i = 0; 

   
    for (int k = 0; k < n; k++) {
    
        top++;
        S[top] = A[k];

        
        while (top >= 0 && S[top] == sortedA[i]) {
            top--;   
            i++;    
        }
    }

    if (i == n) cout << "Possible\n";
    else cout << "Not Possible\n";


}