
 {
	public:
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
 int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        disjoint ds(v);
        int sum=0;
        for(auto it:edges){
            int d=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findpar(u)!=ds.findpar(v)){
                sum+=d;
                ds.unionrank(u,v);
            }
            
            
            
        }
        return sum;
        
        
    }