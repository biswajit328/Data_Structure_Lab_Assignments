#include <iostream>
#include <string>
using namespace std;


bool isSubstring(const string& s1, const string& s2) {
    return s2.find(s1) != string::npos;
}

bool canSplit(const string& s) {
    int n = s.length();
  
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);
            
            if ((isSubstring(a, b) && isSubstring(a, c)) ||
                (isSubstring(b, a) && isSubstring(b, c)) ||
                (isSubstring(c, a) && isSubstring(c, b))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (canSplit(s))
        cout << "YES\n";
    else
        cout << "NO\n";
}