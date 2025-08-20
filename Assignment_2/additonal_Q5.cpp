#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possibleDups = 0;
    int last = n - 1;

   
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
          
            if (i == last - possibleDups) {
                arr[last] = 2;
                last--;
                break;
            }
            possibleDups++;
        }
    }

 
    int i = last - possibleDups;
    int j = last;
    while (i >= 0) {
        if (arr[i] == 2) {
            arr[j--] = 2;
            arr[j--] = 2;
        } else {
            arr[j--] = arr[i];
        }
        i--;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    duplicateTwos(arr, n);
    print(arr, n);
}