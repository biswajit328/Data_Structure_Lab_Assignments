#include <iostream>
using namespace std;

int sol1(int arr[],int size){
    for (int i = 1; i <= size; i++)
    {
        if(arr[i-1]!=i){
            return i;
        }
    }
    return size + 1;
    
}

int sol2(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;
            }
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
    return size + 1;
}

int main(){

int arr[] = {1,2,3,4,5,6,8};
int n = sizeof(arr)/sizeof(arr[0]);
if (sol1(arr,n))
{
    cout<<"Missing no is "<<sol1(arr,n)<<endl;
}
else cout<<"All numbers are present"<<endl;

if (sol2(arr,n))
{
    cout<<"Missing no is "<<sol2(arr,n);
}
else cout<<"All numbers are present";

return 0;
}