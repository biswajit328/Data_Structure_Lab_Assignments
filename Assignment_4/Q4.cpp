#include <iostream>
#include<queue>
using namespace std;

void sol(string str){
    int frq[26] = {0};
    queue<char>q;
    for (char ch :str){
        if(ch == ' ') continue;

        q.push(ch);
        frq[ch - 'a']++;

        while(!q.empty() && frq[q.front() - 'a']>1){
            q.pop();
        }

        if(q.empty()) cout<< -1<<" ";
        else cout<<q.front()<<" ";
    }
}

int main(){

string str = "a a b c";
    cout << "Input: " << str << endl;
    cout << "Output: ";
    sol(str);

}