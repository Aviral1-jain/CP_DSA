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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint ds(n);
        vector<int> ans;
        for(auto edge:edges){
            if(ds.findpar(edge[0])!=ds.findpar(edge[1])){
                ds.unionrank(edge[0],edge[1]);
            }
            else {
                ans={edge[0],edge[1]};
            }
        }
        return ans;

        
    }