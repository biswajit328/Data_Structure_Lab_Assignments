#include <iostream>
using namespace std;

int arr[20];
int size = 0;

void insert()
{
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void display()
{
    cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void insert(int pos, int value){
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    } 
    arr[pos] = value;
    size++;
}

void deleteElement(int pos)
{
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    } 
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}  

void search(int value)
{
    for (int i = 0; i < size; i++) { 
        if (arr[i] == value) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
}   

int main()
{
    insert();
    display();
    cout << endl;
    int pos, value;
    cout << "Enter position and value to insert: ";
    cin >> pos >> value;
    insert(pos, value);
    display();
    cout << endl;
    cout << "Enter position to delete: ";
    cin >> pos;
    deleteElement(pos);
    display();
    cout << endl;
    cout << "Enter value to search: ";
    cin >> value;
    search(value);
    return 0;
}