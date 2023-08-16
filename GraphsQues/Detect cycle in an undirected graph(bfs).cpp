  bool bfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,node});
                }
                else if(par!=x){
                    return true;
                }
            }
            
        }
        
        return false;
        
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                
           if(bfs(i,adj,vis) ){
               return true;
           }
            }
        }
        return false;
        
        
    }