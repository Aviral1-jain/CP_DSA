#include<bits/stdc++.h>
using namespace std;


vector<int> adj[100004];

void dfs(int node,int par){
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node);
        }
    }

}
void subtreesize(int node,int par,int subtree[]){
    cout<<node<<" ";
    int sum=0;
    for(auto it:adj[node]){
        if(it!=par){
            subtreesize(it,node,subtree);
            sum+=subtree[it];
        }
    }
    subtree[node]=1+sum;


}
void dfs1(int node,int par,int &height,int level){
    cout<<node<<" ";
    height=max(height,level);
    for(auto it:adj[node]){
        if(it!=par){
            dfs1(it,node,height,level+1);
        }
    }

}


void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int node=it.first;
        int par=it.second;
        cout<<node<<" ";
        for(auto x:adj[node]){
            if(x!=par){
                q.push({x,node});
            }
        }

    }
}






int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //bfs();
 //   dfs(1,0);
    int height=0;
  //  dfs1(1,0,height,1);
    cout<<endl;
  //  cout<<"height "<<height<<endl;
    int subtree[100005];
    subtreesize(1,0,subtree);
    cout<<endl;
    for(int i=1;i<=n+1;i++){
        cout<<i<<" :" <<subtree[i]<<" ";
    }
    return 0;


}