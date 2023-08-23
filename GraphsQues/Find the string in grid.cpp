  //https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
  int dr[8]={-1,1,0,0,-1,-1,1,1};
    int dc[8]={0,0,-1,1,-1,1,-1,1};
    bool dfs(int i,int j,int addx,int addy,string &word,vector<vector<char>> grid,int ind){
        if(ind==word.size()){
            return true;
        }
        
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=word[ind])return false;
        
         
         return dfs(i+addx,j+addy,addx,addy,word,grid,ind+1);;
                        
        
        
        
        
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n=grid.size();
        int m=grid[0].size();
        int dr[8]={-1,1,0,0,-1,-1,1,1};
        int dc[8]={0,0,-1,1,-1,1,-1,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                for(int k=0;k<8;k++){
                    if(dfs(i+dr[k],j+dc[k],dr[k],dc[k],word,grid,1)){
                     //   cout<<i<<" "<<j;
                        ans.push_back({i,j});
                        break;
                        
                }
            }
                    
         }
        }
    }
        
        return ans;
	}