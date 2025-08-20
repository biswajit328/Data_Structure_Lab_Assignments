#include<iostream>
#include<algorithm>
using namespace std;

bool sol(string str1, string str2) {
    if (str1.size() != str2.size()) return false; // Length check
    int arr1[26] = {0};
    int arr2[26] = {0};
    for (int i = 0; i < str1.size(); i++) {
        arr1[str1[i] - 'a']++;
        arr2[str2[i] - 'a']++;
    }
    return equal(arr1, arr1 + 26, arr2);
}

int main() {
    string st1 = "abcdef";
    string st2 = "fbacde";
    cout << sol(st1, st2);
}