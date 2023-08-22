//dfs
	 void dfs(int node,stack<int> &st,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,st,adj,vis);
            }
        }
        st.push(node);
        return;
        
        
        
        
    }
    
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(v,0);
	    stack<int> st;
	    
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,st,adj,vis);
	        }
	        
	    }
	    
	    
	    vector<int> ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}


//bfs
vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(v,0),inorder(v,0);
	    queue<int> q;
	    
	    for(int i=0;i<v;i++){
	        for(auto x:adj[i]){
	            inorder[x]++;
	        }
	        
	    }
	    for(int i=0;i<v;i++){
	       if(inorder[i]==0)q.push(i);
	        
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int curr=q.front();
	        q.pop();
	        ans.push_back(curr);
	        for(auto x:adj[curr]){
	            inorder[x]--;
	            if(inorder[x]==0)q.push(x);
	        }
	    }
	    return ans;
	}