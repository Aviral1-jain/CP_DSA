#include<bits/stdc++.h>

using namespace std;
#define int long long

//findbridge
int tin[100005],mini[1000005],vis[100005];
vector<int> adj[100005];
int t=1;
void findBridge(int node,int par=0){
    vis[node]=1;
    tin[node]=mini[node]=t++;

    for(auto it:adj[node]){
        if(it==par)continue;
        if(vis[it]==0){
            findBridge(it,node);
            mini[node]=min(mini[node],mini[it]);
            if(mini[it]>tin[node]){
                //print that node its a bridge
                cout<<node << " "<<it<<endl;
              //  printBridge(it,node);
            }
        }
        else{
            mini[node]=min(mini[node],mini[it]);
        }

    }
    

}

int32_t main(){
int v,e;
cin>>v>>e;
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
findBridge(0);
   
return 0;

}