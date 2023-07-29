#include<bits/stdc++.h>
using namespace std;

int path(int i,vector<int> &hts,vector<int> &dp){
    if(i<=0)return 0;
    if(dp[i]!=-1)return dp[i];
    int pick=INT_MAX;
    int notpick=INT_MAX;
   if(i>1)pick=abs(hts[i]-hts[i-2])+path(i-2,hts,dp);
   if(i>0) notpick=abs(hts[i]-hts[i-1])+path(i-1,hts,dp);
    return dp[i]=min(pick,notpick);
}
int path1(int i,vector<int> &hts,int k,vector<int> &dp){
    if(i<=0)return 0;
    if(dp[i]!=-1)return dp[i];
    int pick=INT_MAX;
    for(int ind=1;ind<=k;ind++){
        if(i-ind>=0){
            pick=min(pick,abs(hts[i]-hts[i-ind])+path1(i-ind,hts,k,dp));
        }
    }
    return dp[i]=pick;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> hts(n);
    for(auto &x:hts)cin>>x;
    vector<int> dp(n,-1);
    cout<<path1(n-1,hts,k,dp);

}