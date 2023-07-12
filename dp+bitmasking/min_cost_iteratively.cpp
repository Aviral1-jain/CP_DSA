#include<bits/stdc++.h>
using namespace std;


int minCost(int cost[4][4],int n,int p,int mask,vector<int> &dp){
    if(p>=n){
        return 0;
    }
    if(dp[mask]!=-1)return dp[mask];
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(!(mask &(1<<i))){
            int ans=minCost(cost,n,p+1,mask|(1<<i),dp)+cost[p][i];
            mini=min(mini,ans);

        }
    }
        return dp[mask]=mini;
}

int minCostiter(int cost[4][4],int n){
    vector<int> dp((1<<n),INT_MAX);
    dp[0]=0;
    for(int mask=0;mask<((1<<n)-1);mask++){
        int temp=mask;
        int k=0;
        while(temp>0){
            if(temp%2==1){
                k++;
            }
            temp=temp/2;
        }
    for(int j=0;j<n;j++){
       if(!(mask &(1<<j))){
            dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+cost[k][j]);

       }
    }
    }

    return dp[(1<<n)-1];

}
int main(){
    int cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    vector<int> dp((1<<4),-1);
    cout<<minCost(cost,4,0,0,dp)<<endl;
    cout<< minCostiter(cost,4)<<endl;
   
    return 0;
}