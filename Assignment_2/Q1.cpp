#include <iostream>
using namespace std;

bool binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return true;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }   
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main(){

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 10;
    cout<<binarySearch(arr, 10, k) << endl;
   
    return 0;
}