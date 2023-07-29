#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//https://codeforces.com/problemset/problem/25/D
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

void cf25D(){
    int n;
    cin>>n;
   
    vector<pair<int,int>> oldroads;
    disjoint ds(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        if(ds.findparent(u)==ds.findparent(v)){
            oldroads.push_back({u,v});
         
        }
        else{
            ds.unionsize(u,v);
        }
    }

    //find number of components
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(ds.findparent(i));
    }
    cout<<st.size()-1<<endl;
    int numcompo=st.size();
    vector<int> components(st.begin(),st.end());

    for(int i=0;i<numcompo-1;i++){
        cout<<oldroads[i].first<<" "<<oldroads[i].second<<" "<<components[i]<<" "<<components[i+1]<<endl;


    }


    
    
    return;
    
}

int main(){

    cf25D();

    return 0;
}