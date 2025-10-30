#include <iostream>
using namespace std;
#define MAX 10

void interleave(int arr[], int n) {
    int half = n / 2;
    int q1[MAX], q2[MAX];
    int r1 = -1, r2 = -1;

    for (int i = 0; i < half; i++) q1[++r1] = arr[i];
    for (int i = half; i < n; i++) q2[++r2] = arr[i];

    int k = 0, i = 0, j = 0;
    while (i <= r1 && j <= r2) {
        arr[k++] = q1[i++];
        arr[k++] = q2[j++];
    }
    while (i <= r1) arr[k++] = q1[i++];
    while (j <= r2) arr[k++] = q2[j++];
}

int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = 6;

    cout << "Original Queue: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    interleave(arr, n);

    cout << "Interleaved Queue: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
