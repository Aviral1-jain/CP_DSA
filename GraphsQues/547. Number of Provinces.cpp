
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
       
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
        return ;
    }

    int findCircleNum(vector<vector<int>>& conn) {
        int n=conn.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(conn[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;

        
    }