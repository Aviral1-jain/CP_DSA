 #include <bits/stdc++.h> 
using namespace std;



class Solution {
  public:
  class disjoint{
    vector<int> rank,par;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findpar(int node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findpar(par[node]);
    }

    void unionrank(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);

        if(ulp_u==ulp_v)return;
         if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            par[ulp_v]=ulp_u;
        }
        else{
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        vector<vector<int>> mat(n,vector<int>(m,0));
        disjoint ds(n*m);
        int cnt=0;
        vector<int> ans;
        
        for(auto it:operators){
           int r=it[0];
           int c=it[1];
           if(mat[r][c]==1){
               ans.push_back(cnt);
               continue;
           }
           mat[r][c]=1;
           cnt++;
           
           
           for(int k=0;k<4;k++){
               int newr=r+dr[k];
               int newc=c+dc[k];
               if(newr>=0 && newr<n && newc>=0 && newc<m){
                   if(mat[newr][newc]==1){
                       int node=r*m+c;
                       int val=newr*m+newc;
                       if(ds.findpar(node)!=ds.findpar(val)){
                           cnt--;
                        ds.unionrank(node,val);
                       }
                     
                       
                       
                   }
                   
               }
           }
           ans.push_back(cnt);
  
        }
        return ans;
    }
};