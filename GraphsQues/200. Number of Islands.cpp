 int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

    void dfs(int i,int j,vector<vector<char>>& grid){
      //  vis[i][j]=1;
      grid[i][j]='#';
        int n=grid.size();
        int m=grid[0].size();

        for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m &&  grid[newr][newc]=='1'){
                dfs(newr,newc,grid);
            }
        }
        return;

    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
     //   vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }

        }
        return ans;

    }