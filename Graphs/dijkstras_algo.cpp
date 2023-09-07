#include<bits/stdc++.h>
using namespace std;


void dijkstra(int** edges,int n){
    bool* vis=new bool[n]();
    int* dist=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    for(int i=0;i<n-1;i++){
       int minver=getminvertex(dist,vis);
       vis[minver]=true;
       for(int j=0;j<n;j++){
        if(edges[minver][j] && !vis[j]){
            int curr=dist[]
        }
       } 
    }

}
int main(){

int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    dijkstra(edges,n);
    return 0;
}