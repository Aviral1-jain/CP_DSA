#include<bits/stdc++.h>
using namespace std;


int path(int ind,int prev,vector<vector<int>> &dp,vector<vector<int>> &points){
    if(ind==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=prev){
                maxi=max(points[0][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=prev){
          int  point=points[ind][i]+path(ind-1,i,dp,points);
          maxi=max(maxi,point);
        }
        
    }
    return dp[ind][prev]=maxi;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<< path(n-1,3,dp,points)<<endl;
    

}


