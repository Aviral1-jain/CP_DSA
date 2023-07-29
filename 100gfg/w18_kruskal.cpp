#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class disjoint{
    public:
    vector<int> parent,size;
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

void kruskal(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>w>>u>>v;
        edges.push_back({w,{u,v}});
    }
    // m*logm
    sort(edges.begin(),edges.end());
    int smm=0;
    vector<pair<int,int>> mst;
    disjoint ds(n);
    // m*4alpha
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findparent(u)!=ds.findparent(v)){
            ds.unionsize(u,v);
            smm+=wt;
            mst.push_back({u,v});

        }
        
    }
    cout<<smm<<endl;
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return;
    
}
//input
// 6
// 9
// 9 5 4
// 5 4 3
// 1 4 1
// 4 5 1
// 2 1 2
// 3 4 2
// 3 3 2
// 7 2 6
// 8 3 6
// 17

int main(){
    kruskal();

    return 0;
}
