#include<bits/stdc++.h>
using namespace std;

void scanlinealgo(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prefix[n+1];
    int q;
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        prefix[l]+=x;
        prefix[r+1]-=x;

    }
    int s=0;
    for(int i=0;i<n;i++){
        s+=prefix[i];
        arr[i]+=s;
        

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";


    }

}

void solve2dprefix(){
    int n,m;
    cin>>n>>m;
    int arr[n][m],prefix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefix[i][j]=arr[i][j];
            if(i-1>=0)prefix[i][j]+=prefix[i-1][j];
            if(j-1>=0)prefix[i][j]+=prefix[i][j-1];
            if(j-1>=0 && i-1>=0)prefix[i][j]-=prefix[i-1][j-1];

        }
    }

    int q;
    cin>>q;
    while(q--){
        int r1,r2,c1,c2;
        cin>>r1>>r2>>c1>>c2;


    }

  return;
}




int main(){

    
    int t;
    cin>>t;
    while(t--){
        solve();

        
        
    }
    return 0;
}