#include <iostream>
using namespace std;

string concatenateStrings(const string& str1, const string& str2) {
    return str1 + str2;
}

string reverse(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
    return str;
}

bool isvowel(char ch) {
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

string removeVowels(string& str) {
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if(!isvowel(str[i])) {
            str[j++] = str[i];
        }
    }
    str.resize(j);
    return str;
}

void sort(string &str){
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = 0; j < str.size() - i - 1; j++) {
            if (tolower(str[j]) > tolower(str[j + 1])) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

string upper_to_lowercase(string &str){
    for(char &ch: str){
        if(ch<='Z' && ch>='A'){
            ch = ch - 'A' + 'a';
        }
    }
    return str;
}

int main(){

    string str = "Hello";
    string str2 = " hi";
    string str3 = "beautiful";
    string str4 = "BiSwAjIt";
    cout<<concatenateStrings(str, str2) << endl;
    cout << reverse(str) << endl;
    cout << removeVowels(str3) << endl;
    sort(str4);
    cout<<str4;
    cout<<upper_to_lowercase(str3);

}