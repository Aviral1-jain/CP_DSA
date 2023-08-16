   vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(v,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto x:adj[curr]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                    
                }
            }
        }
        return ans;
        
    }