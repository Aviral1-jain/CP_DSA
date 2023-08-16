class Solution {
public:
 int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>> &vis){
      vis[i][j]=1;
   
        int n=grid.size();
        int m=grid[0].size();

        for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m &&  grid[newr][newc]=='O' && !vis[newr][newc]){
                dfs(newr,newc,grid,vis);
            }
        }
        return;

    }

    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
      

        for(int i=0;i<n;i++){
            if(grid[i][0]=='O' && !vis[i][0] ){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]=='O' && !vis[i][m-1] ){
                dfs(i,m-1,grid,vis);
            }

        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O' && !vis[0][i]){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,grid,vis);
            }


        }
        
         vector<vector<char>> ans(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j])ans[i][j]='O';
            }
          
          
        }
        grid=ans;
        return ;
    }
};