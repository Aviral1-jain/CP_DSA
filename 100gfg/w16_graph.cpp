#include<bits/stdc++.h>

using namespace std;
#define int long long

int vis[1000005];
//number of components 
void bfs(int node){
    vis[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

//number of components
void dfs(int node){
    vis[node]=1;
    
        for(auto it:adj[node]){
            if(!vis[it]){
               
                dfs(it);
            }
        }
    
}
//topological
void topo (int node){
    vis[node]=1;
    
        for(auto it:adj[node]){
            if(!vis[it]){
               
                dfs(it);
            }
        }
        st.push(node); 
    
}
//detect cycle
bool cycledetectionug(int node,int par){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){

        if(cycledetectionug(it,node)==true)return true;
        else if(it!=par)return true;
        }
    }
    return false;
}

bool cycledetectionDG(int node,int par){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){

        if(cycledetectionDG(it,node)==true)return true;
        else if(pathvis[it]==1)return true;
        }
    }
      pathvis[node]=0;
    return false;
}

void cycle(){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag=flag | cycledetectionDG(i,0);
        }
    }
    if(flag==1)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}





int32_t main(){

   
return 0;

}