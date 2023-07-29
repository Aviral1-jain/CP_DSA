#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
vector<int> adj[100005];


void shortestpath(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v ; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        
    }

    set<pair<int,pair<int,int>>> fbt;
    for(int i=0;i<k;i++){
        int u,v,x;
        cin>>u>>v>>x;
        fbt.insert({x,{u,v}});
    }
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e15));
    dist[1][1]=0;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{1,1}});
    int shortestdis=-1,lastNode=0;
    while(!q.empty()){
        auto it=q.front();
        int dis=it.first;
        int node=it.second.first;
        int prev=it.second.second;
        q.pop();
        if(node==n){
            shortestdis=dis;
            lastNode=prev;
            break;
        }

        for(auto it:adj[node]){
         
            if(dis+1<dist[it][node] &&  fbt.find({prev,{node,it}})==fbt.end()){

                dist[it][node]=dis+1;
                q.push({dis+1,{it,node}});

            }
        }

    }
    if(shortestdis==-1){
         cout<<shortestdis<<endl;
         return;
    }
    vector<int> path;
    path.push_back(n);
    path.push_back(lastNode);
    cout<<shortestdis<<endl;
    while(lastNode!=1){
        shortestdis--;
        for(int i=1;i<=n;i++){
            if(dist[lastNode][i]==shortestdis){
                lastNode=i;
                break;
            }

        }
        path.push_back(lastNode);
    }
    reverse(path.begin(),path.end());
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;



    return;





}

int32_t main(){
    shortestpath();
    return 0;
}