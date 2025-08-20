#include <iostream>
using namespace std;

void sol(int arr[3][3]){
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[0][i];
    }
    cout<<"Sum of row 1 is: "<<sum<<endl;
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[1][i];
    }
    cout<<"Sum of row 2 is: "<<sum<<endl;
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[2][i];
    }
    cout<<"Sum of row 3 is: "<<sum<<endl;
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[i][0];
    }
    cout<<"Sum of column 1 is: "<<sum<<endl;
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[i][1];
    }
    cout<<"Sum of column 2 is: "<<sum<<endl;
    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum+=arr[i][2];
    }
    cout<<"Sum of column 3 is: "<<sum<<endl;
    sum = 0;

}

int main(){

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol(arr);
}