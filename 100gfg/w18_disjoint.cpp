#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int> parent,size;
    public:
    disjoint(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;

        }
      

    }


    int findparent(int node){
        if(node==parent[node]){
            return node;

        }
        //path compression
        return parent[node]=findparent(parent[node]);
    }

    void unionsize(int u,int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v){
            return ;
        }

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }





};


int main(){

    disjoint ds(7);
    ds.unionsize(1,2);
    ds.unionsize(2,3);
    ds.unionsize(4,5);
    ds.unionsize(6,7);
    ds.unionsize(5,6);

    if(ds.findparent(3)==ds.findparent(7)){
        cout<<"same"<<endl;
    }
    else{
cout<<"not_same"<<endl;
    }
    ds.unionsize(3,7);
    if(ds.findparent(3)==ds.findparent(7)){
        cout<<"same"<<endl;
    }
    else{
cout<<"not_same"<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int type,u,v;
        cin>>type>>u>>v;
        if(type==1){
            ds.unionsize(u,v);
        }
        else{
            if(ds.findparent(u)==ds.findparent(v)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }



    return 0;
}