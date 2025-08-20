#include <iostream>
using namespace std;

int arr[20];
int size = 0;
void insert(){
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";  
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void deleteElement(int pos) {
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void remove_duplicates() {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                deleteElement(j);
                j--;
            }
        }
    }
}

int main(){

    insert();
    cout << "Original array: ";
    print();
    cout << endl;
    remove_duplicates();
    cout << "After removing duplicates array: ";
    print();
    
}