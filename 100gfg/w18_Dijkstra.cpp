#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
//https://codeforces.com/contest/20/problem/C
vector<pair<int,int>> adj[100004];
void shortestpath(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n+1,1e15);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> par(n+1,0);
    while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        pq.pop();
       
        for(auto it:adj[node]){
            int wt=it.second;
            int adjnode=it.first;
            if(dis+wt<dist[adjnode]){
                dist[adjnode]=dis+wt;
                par[adjnode]=node;
                pq.push({dist[adjnode],adjnode});
            }
        }

    }
    if(dist[n]==1e15){
        cout<<-1<<endl;
        return;
    }
    vector<int> path;
    path.push_back(n);
    int lastnode=n;
    while(lastnode!=1){
        lastnode=par[lastnode];
        path.push_back(lastnode);
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

