void adjacency_matrix(int v,int e){
    int **p;
    p=new int*[v];
    for(int i=0;i<v;i++){
        p[i]=new int[v];
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            p[i][j]=0;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
           cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter first vertex:";
        cin>>a;
        cout<<"Enter second vertex:";
        cin>>b;
        p[a][b]++;
        p[b][a]++;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
           cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}