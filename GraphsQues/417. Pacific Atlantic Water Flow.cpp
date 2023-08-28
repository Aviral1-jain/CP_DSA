class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false)),atl(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,m-1);
        }
        for(int i=0;i<m;i++){
            dfs(heights,pac,0,i);
            dfs(heights,atl,n-1,i);
        }
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back(vector<int>{i, j});
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,int i,int j){
        int n=heights.size();
        int m=heights[0].size();
        vis[i][j]=true;
        if(i-1>=0 && vis[i-1][j] != true && heights[i-1][j]>=heights[i][j]){
             dfs(heights,vis,i-1,j);
        }
         if(i+1<n && vis[i+1][j] != true && heights[i+1][j]>=heights[i][j]){
             dfs(heights,vis,i+1,j);
        }
          if(j+1<m && vis[i][j+1] != true && heights[i][j+1]>=heights[i][j]){
             dfs(heights,vis,i,j+1);
        }
              if(j-1>=0 && vis[i][j-1] != true && heights[i][j-1]>=heights[i][j]){
             dfs(heights,vis,i,j-1);
        }
    }
};