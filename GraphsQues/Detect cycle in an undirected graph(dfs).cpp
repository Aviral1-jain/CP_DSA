 bool dfs(int node,int par,vector<int> &vis,vector<int> adj[]){
      vis[node]=1;
      
      for(auto x:adj[node]){
          if(!vis[x]){
              if(dfs(x,node,vis,adj))return true;
          }
          else if(x!=par)return true;
      }
      return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                
            if(dfs(i,-1,vis,adj))return true;
            }
        }
        return false;
        
    }