 #include <bits/stdc++.h> 
using namespace std;


class Solution {
public:

    int dfs(int g1ind,int mask,vector<vector<int>>& cost,vector<int> &g2cost,int n,int m,vector<vector<int>> &dp){
        if(g1ind==n){
            int s=0;
            for(int j=0;j<m;j++){
                if((mask & (1<<j))==0){
                    s+=g2cost[j];

                }
            }
            return s;
        }
        if(dp[g1ind][mask]!=-1)return dp[g1ind][mask];

        int sumcost=INT_MAX;
        for(int j=0;j<m;j++){
                int pick=cost[g1ind][j];
                sumcost=min(sumcost,pick+dfs(g1ind+1,mask | (1<<j),cost,g2cost,n,m,dp));
        }
        return dp[g1ind][mask]=sumcost;

    }

    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size();
        int m=cost[0].size();
        vector<int> g2cost(m,500);
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                g2cost[j]=min(g2cost[j],cost[i][j]);
            }
        }
        vector<vector<int>> dp(n+1,vector<int>((1<<m),-1));
    //    dfs(0,0,cost,g2cost,n,m);
   //     for(auto it:g2cost)cout<<it<<" ";
        return dfs(0,0,cost,g2cost,n,m,dp);
    }
};