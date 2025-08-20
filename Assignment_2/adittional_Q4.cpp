#include<iostream>
using namespace std;

void sol(int arr[], int n) {
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (arr[j] == 0) {
            swap(arr[i], arr[j]);
            i++; j++;
        }
        else if (arr[j] == 2) { 
            swap(arr[j], arr[k]);
            k--;
        }
        else { 
            j++;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[5] = {2, 1, 0, 2, 0};
    sol(arr, 5);
    print(arr, 5);
}