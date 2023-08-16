void dfs(int i,int j,vector<vector<int>>& grid,int color,int col){
        grid[i][j]=color;
        int n=grid.size();
        int m=grid[0].size();
        
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m &&  grid[newr][newc]==col){
        
                dfs(newr,newc,grid,color,col);
            }
        }
        return;

    }

    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        if(grid[sr][sc]==color)return grid;
        int col=grid[sr][sc];
        int n=grid.size();
        int m=grid[0].size();
        dfs(sr,sc,grid,color,col);
      
        
        return grid;

    }