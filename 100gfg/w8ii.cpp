#include<bits/stdc++.h>
using namespace std;


double path(int ind,int head,vector<vector<double>> &dp,vector<double> &prob){
    if(ind<0){
        if(head>(prob.size()-head))return 1.0;
        else return 0.0;
        
    }
    if(dp[ind][head]!=-1)return dp[ind][head];
    double pick=prob[ind]*path(ind-1,head+1,dp,prob);
    double notpick=((double)(1.0-prob[ind])*path(ind-1,head,dp,prob));
    return dp[ind][head]=pick+notpick;
}

int main(){
    int n;
    cin>>n;
    vector<double> prob(n);
    for(int i=0;i<n;i++){
        cin>>prob[i];

        }
    
    vector<vector<double>> dp(n,vector<double>(n+1,-1));
    cout<< path(n-1,0,dp,prob)<<endl;
    

}
