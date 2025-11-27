/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
      
        Node* mid1;
        Node* mid2;
      
        Node*temp=head;
        if(temp->next==head){
            return make_pair(head,nullptr);
            
        }
        else{
            Node*slow=head;
            Node*fast=head;
            
            while(fast->next!=head&&fast->next->next!=head){
                fast=fast->next->next;
                slow=slow->next;
                
            }
            mid1=slow;
            mid2=slow->next;
            Node*mid=mid2;
            mid1->next=head;
            while(mid2->next!=head){
                mid2=mid2->next;
                
            }
            mid2->next=mid;
            
            return make_pair(head,mid);
            }
    }
}

;