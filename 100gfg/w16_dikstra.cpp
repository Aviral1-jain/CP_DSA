#include<bits/stdc++.h>

using namespace std;
#define int long long

vector<pair<int,int>> adj[100005];


void findshortest(int src,int n){
    vector<int> dist(n+1,1e9);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto node=pq.top().second;
        
        auto dis=pq.top().first;
        pq.pop();

        for(auto el:adj[node]){
            int it=el.first;
            int wt=el.second;
            if(wt+dis<dist[it]){
                dist[it]=dis+wt;
                pq.push({dist[it],it});

            }
        }

        for(int i=0;i<n;i++){
            cout<<dist[i]<<" ";
        }


    }


}

void djisktra(){
    int n,m;
cin>>n,m;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

}
int32_t main(){
djisktra();
   
return 0;

}