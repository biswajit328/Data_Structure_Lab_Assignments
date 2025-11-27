void adjacency_list(Node* adj[],int v,int e){
    for(int i=0;i<v;i++){
            adj[i]=new Node(i);
        }
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter first vertex:";
        cin>>a;
        cout<<"Enter second vertex:";
        cin>>b;
        
        Node* temp=new Node(b);
        temp->next=adj[a]->next;
        adj[a]->next=temp;

        Node* temp2=new Node(a);
        temp2->next=adj[b]->next;
        adj[b]->next=temp2;

        
    }
    
}
void lis_show(Node* adj[],int v){
    for(int i=0;i<v;i++){
        Node* temp=adj[i];
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
}