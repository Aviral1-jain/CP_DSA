 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>> q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans=mat;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    vis[i][j]=1;
                    q.push({0,{i,j}});

                }
            }
        }
        while(!q.empty()){
            int cost=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            ans[i][j]=cost;
            for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m &&  mat[newr][newc]==1 && !vis[newr][newc]){
                vis[newr][newc]=1;
                q.push({cost+1,{newr,newc}});
            }
        }

        }
        return ans;

    }