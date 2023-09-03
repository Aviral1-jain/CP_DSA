#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/meet-up_2698977?leftPanelTab=0

int bfs(int i,int j,vector<string> grid,int cnt){
    int n=grid.size();
    int m=grid[0].size();    
    vector<vector<int>> vis(n,vector<int>(m,0));
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    queue<pair<int,pair<int,int>>> q;
    int sum=0;
    q.push({0,{i,j}});
    vis[i][j]=1;
    while(!q.empty()){
        int cost=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        q.pop();
        if(grid[r][c]=='F'){
            sum+=cost;
            cnt--;
            if(cnt==0)return sum;
            else
            continue;
        }
        for(int k=0;k<4;k++){
            int newr=r+dr[k];
            int newc=c+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]!='#' && !vis[newr][newc] ){
                q.push({cost+1,{newr,newc}});
                
                vis[newr][newc]=1;
            }
        }
    }
    return 1e9;



}

int meetUp(vector<string> grid)
{
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='F'){
                cnt++;
            }
        }
    }
    if(cnt==0)return 0;
    int mini=1e9;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                int currd=bfs(i,j,grid,cnt);
                mini=min(currd,mini);

            }


        }
    }
    return mini==1e9?-1:mini;

    

}