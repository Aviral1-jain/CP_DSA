//https://leetcode.com/problems/cherry-pickup/description/

#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:

    int path(int i1,int j1,int i2,int n,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int j2=i1+j1-i2;
        if( i1>=n  || i2>=n  || j1>=n  || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return INT_MIN;
        }
    if(i1==n-1 && j1==n-1)return grid[i1][j1];
    if(dp[i1][j1][i2]!=-1)return dp[i1][j1][i2];
    int cherry=0;
        if(i1==i2 && j1==j2){
            cherry+=grid[i1][j1];
        }
        else{
            cherry+=grid[i2][j2]+grid[i1][j1];

        }
        int hh=path(i1,j1+1,i2,n,grid,dp);
        int vh=path(i1+1,j1,i2,n,grid,dp);
        int hv=path(i1,j1+1,i2+1,n,grid,dp);
        int vv=path(i1+1,j1,i2+1,n,grid,dp);
        return dp[i1][j1][i2]=cherry+max({hh,vh,hv,vv});


    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
    //vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n, vector<int>(n, -1))) );
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(n, -1)));
    
        if(path(0,0,0,n,grid,dp)<0)return 0;
        else return path(0,0,0,n,grid,dp) ;


    }
};
