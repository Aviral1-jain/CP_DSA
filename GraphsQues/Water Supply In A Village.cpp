// https://www.codingninjas.com/studio/problems/water-supply-in-a-village_1380956?leftPanelTab=0

#include<bits/stdc++.h>

class disjoint{
    public:
    vector<int> rank,par;
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

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	// Write your code here.
	  vector<pair<int,pair<int,int>>> edges;
	  for(int i=1;i<=n;i++){
		  edges.push_back({wells[i-1],{0,i}});
	  }
	  for(int i=0;i<k;i++){
		  edges.push_back({pipes[i][2],{pipes[i][0],pipes[i][1]}});
	  }

	   sort(edges.begin(),edges.end());
	   disjoint ds(n+1);
	   int mini=0;
	   for(auto it:edges){
		   int c=it.first;
		   int u=it.second.first;
		   int v=it.second.second;

		   if(ds.findpar(u)==ds.findpar(v)){
			   continue;
		   }
		   else {
			   mini+=c;
			   ds.unionrank(u, v);
		   }
	   }
	   return mini;




}