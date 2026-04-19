void edge_list(Node* edg[],int e){
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter first vertex:";
        cin>>a;
        cout<<"Enter second vertex:";
        cin>>b;
        edg[i]=new Node(a);
        Node* temp=new Node(b);

        edg[i]->next=temp;
    }


}
void edg_listshow(Node* edg[],int e){
    for(int i=0;i<e;i++){
        Node* temp=edg[i];
        while(temp->next!=NULL){
            cout<<temp->val<<"-----";
            temp=temp->next;
        }
        cout<<temp->val<<endl;
    }
}
