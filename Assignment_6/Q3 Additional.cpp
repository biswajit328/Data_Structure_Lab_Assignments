#include <bits/stdc++.h> 
/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/

Node* reverseDLLInGroups(Node* head, int k)
{	Node* node=head;
Node*dummy_head=NULL;
    int count=0;
	

    while(node!=NULL){
		node=node->next;
		count++;
	}
	

	int reverse=count/k;
	
	if(k==1){
		return head;
	}
	else{
		Node*dummy=head;
		Node*prev=NULL;
		Node*next=NULL;
		Node*last=NULL;
		Node*first=NULL;
		if(count>k){
		
		
		

		for(int i=1;i<k;i++){
		  Node* next=dummy->next;
		  
		   dummy->next=dummy->prev;
		   dummy->prev=next;
		   dummy=next;
		}
		last=head;
		dummy_head=dummy;
		next=dummy->next;
		dummy->next=dummy->prev;
		dummy->prev=first;
		dummy=next;

		for(int j=1;j<reverse;j++){
			first=dummy;
			for(int o=1;o<k;o++){
				next=dummy->next;
				dummy->next=dummy->prev;
				dummy->prev=next;
				dummy=next;

			}
			next=dummy->next;
			dummy->next=dummy->prev;
			dummy->prev=last;
			last->next=dummy;
			dummy=next;
			last=first;


		}
		if(dummy!=NULL){
			first=dummy;
			while(dummy->next!=NULL){
				next=dummy->next;
				dummy->next=dummy->prev;
				dummy->prev=next;
				dummy=next;
			}
			dummy->next=dummy->prev;;
			dummy->prev=last;
			last->next=dummy;
			first->next=NULL;
			
		}
		else{
		last->next=NULL;}}
		else{
			if(dummy!=NULL){
			
			while(dummy->next!=NULL){
				next=dummy->next;
				dummy->next=dummy->prev;
				dummy->prev=next;
				dummy=next;
			}
			next=dummy->next;
				dummy->next=dummy->prev;
				dummy->prev=next;
				dummy_head=dummy;
				
			
			
			
		}
		}




	}
	return dummy_head;
}
