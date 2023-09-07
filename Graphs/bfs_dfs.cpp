#include<bits/stdc++.h>
using namespace std;


void printg(int** edges,int n,int s,bool* vis){
    cout<<s<<endl;
    vis[s]=true;
    for(int i=0;i<n;i++){
        if(i==s)continue;
        if(edges[s][i]==1){
            if(vis[i])continue;
            printg(edges,n,i,vis);
        }

    }
}
void printbfs(int** edges,int n,int s,bool* vis){
    queue<int> pending;
  
    pending.push(s);
    vis[s]=true;
   while(!pending.empty()){
    int curr=pending.front();
    pending.pop();
    cout<<curr<<endl;
    for(int i=0;i<n;i++){
        if(i==curr)continue;
        if(edges[curr][i]==1 && !vis[i]){
            pending.push(i);
            vis[i]=true;
        }
    }
   }
}
void bfs(int** edges,int n){
    bool* vis=new bool[n];
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            printbfs(edges,n,i,vis);
        }
    }
}
void dfs(int** edges,int n){
 bool* vis=new bool[n];
    for(int i=0;i<n;i++){
        vis[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            printg(edges,n,i,vis);
        }
    }
}


int main(){

    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++)edges[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;

    }
   
  
    cout<<"dfs"<<endl;
 //   printg(edges,n,0,vis);
 dfs(edges,n);
    cout<<"bfs"<<endl;
    bfs(edges,n);
    return 0;
}