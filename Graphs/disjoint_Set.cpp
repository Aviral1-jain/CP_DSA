#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int> rank,parent;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;

        }
    }


    int findparent(int node){
        if(node==parent[node]){
            return node;

        }
        //path compression
        return parent[node]=findparent(parent[node]);
    }

    void unionrank(int u,int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v){
            return ;
        }

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }





};


int main(){

    disjoint ds(7);
    ds.unionrank(1,2);
    ds.unionrank(2,3);
    ds.unionrank(4,5);
    ds.unionrank(6,7);
    ds.unionrank(5,6);
    //if 3 and7 are same or not
    if(ds.findparent(3)==ds.findparent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"not_same"<<endl;
    }
    ds.unionrank(3,7);
     if(ds.findparent(3)==ds.findparent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"not_same"<<endl;
    }
 //   ds.unionrank(1,2);
return 0;

}