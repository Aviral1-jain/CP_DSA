int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    grid[i][j]=-1;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int time=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            ans=max(ans,time);
            for(int k=0;k<4;k++){
                int newr=r+dr[k];
                int newc=c+dc[k];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                    q.push({time+1,{newr,newc}});
                    grid[newr][newc]=-1;
                }

            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }