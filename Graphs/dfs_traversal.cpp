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
    bool* vis=new bool[n];
    for(int i=0;i<n;i++){
        vis[i]=false;
    }

    printg(edges,n,0,vis);
    return 0;
}