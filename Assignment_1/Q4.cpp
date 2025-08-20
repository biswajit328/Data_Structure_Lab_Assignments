#include <iostream>
using namespace std;

void reverse(int arr[], int size) {
    for (int i = 0; i < size/2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}    

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void matrix_multiply(int a[2][3], int b[3][2], int c[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void print_matrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(int arr[2][3],int d[3][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            d[j][i] = arr[i][j];
        }
    }
}

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int c[2][2];
    int d[3][2];
    reverse(arr, 5);
    cout << "Reversed array: ";
    print_array(arr, 5);
    cout << endl;
    matrix_multiply(a, b, c);
    cout << "Matrix multiplication result: " << endl;
    print_matrix(c);
    cout << endl;
    transpose(a, d);
    cout << "Transposed matrix: " << endl;
    print_matrix(d);
    cout << endl;
}