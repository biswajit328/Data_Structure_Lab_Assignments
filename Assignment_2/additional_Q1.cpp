#include<iostream>
using namespace std;

int sol(int arr[], int size, int k) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(abs(arr[i] - arr[j]) == k) count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 4, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << sol(arr, n, k);
}