#include<bits/stdc++.h>
using namespace std;

int find_touches(int pos,int mask,vector<string> &v,vector<vector<int>> &dp){
    if((mask &(mask-1))==0)return 0;
    if(pos<0){
        return 10000;
    }
    if(dp[pos][mask]!=INT_MAX)return dp[pos][mask];
    int newmask1=0;
    int newmask2=0;
    int touches=0;
    for(int i=0;i<v.size();i++){
        if(mask&(1<<i)){
            touches++;
            if(v[i][pos]=='0'){
                newmask1 |=1<<i;
            }
            else{
                  newmask2 |=1<<i;
            }

        }
    }
    int ans1=find_touches(pos-1,newmask1,v,dp)+find_touches(pos-1,newmask2,v,dp)+touches;
    int ans2=find_touches(pos-1,mask,v,dp);
    int ans=min(ans1,ans2);
    dp[pos][mask]=ans;
    return ans;



}



int main(){
   
  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       
        vector<string> v;
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        int l=v[0].size();
        vector<vector<int>> dp(l,vector<int>(((1<<n+1)),INT_MAX));
        cout<< find_touches(l-1,((1<<n)-1),v,dp)<<endl;

    }
    
    return 0;
}
