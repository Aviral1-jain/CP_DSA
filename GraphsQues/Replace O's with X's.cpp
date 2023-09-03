#include <bits/stdc++.h> 
using namespace std;

public:
   int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

    void dfs(int i,int j, vector<vector<char>> &mat,vector<vector<int>> &vis,int n, int m){
        vis[i][j]=1;
     for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr<n && newr>=0 && newc<m && newc>=0 && mat[newr][newc]=='O'){
                mat[newr][newc]='X';
              
                dfs(newr,newc,mat,vis,n,m);
                
            }
        }
        return;
        
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> mat1(n,vector<char>(m));
        mat1=mat;
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O')dfs(i,0,mat,vis,n,m);
            if(mat[i][m-1]=='O')dfs(i,m-1,mat,vis,n,m);
        }
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O')dfs(0,j,mat,vis,n,m);
            if(mat[n-1][j]=='O')dfs(n-1,j,mat,vis,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat1[i][j]=='O' && !vis[i][j])mat1[i][j]='X';
            }
        }
        return mat1;
    }