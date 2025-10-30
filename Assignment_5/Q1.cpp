#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){data=val;next=NULL;}
};
class LinkedList{
    Node* head;
public:
    LinkedList(){head=NULL;}
    void insertBeg(int x){
        Node* n=new Node(x);
        n->next=head;
        head=n;
    }
    void insertEnd(int x){
        Node* n=new Node(x);
        if(!head){head=n;return;}
        Node* t=head;
        while(t->next)t=t->next;
        t->next=n;
    }
    void insertBefore(int val,int x){
        if(!head)return;
        if(head->data==val){insertBeg(x);return;}
        Node* t=head;
        while(t->next&&t->next->data!=val)t=t->next;
        if(t->next){Node* n=new Node(x);n->next=t->next;t->next=n;}
    }
    void insertAfter(int val,int x){
        Node* t=head;
        while(t&&t->data!=val)t=t->next;
        if(t){Node* n=new Node(x);n->next=t->next;t->next=n;}
    }
    void deleteBeg(){
        if(!head)return;
        Node* d=head;
        head=head->next;
        delete d;
    }
    void deleteEnd(){
        if(!head)return;
        if(!head->next){delete head;head=NULL;return;}
        Node* t=head;
        while(t->next->next)t=t->next;
        delete t->next;
        t->next=NULL;
    }
    void deleteVal(int val){
        if(!head)return;
        if(head->data==val){deleteBeg();return;}
        Node* t=head;
        while(t->next&&t->next->data!=val)t=t->next;
        if(t->next){Node* d=t->next;t->next=d->next;delete d;}
    }
    void search(int val){
        Node* t=head;int pos=1;
        while(t){if(t->data==val){cout<<"Found at position "<<pos<<endl;return;}t=t->next;pos++;}
        cout<<"Not Found"<<endl;
    }
    void display(){
        Node* t=head;
        while(t){cout<<t->data<<" ";t=t->next;}
        cout<<endl;
    }
};
int main(){

}