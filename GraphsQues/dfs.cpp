 
    void dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &ans){
        vis[i]=1;
        ans.push_back(i);
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,ans);
            }
        }
        return;
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        vector<int> ans;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
        return ans;
    }