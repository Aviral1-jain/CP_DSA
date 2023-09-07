#include<bits/stdc++.h>
using namespace std;

int getminvertex(bool* vis,int* weight,int n){
    int minver=-1;
    for(int i=0;i<n;i++){
        if(!vis[i] && ((minver==-1 ) || (weight[minver]>weight[i]))){
            minver=i;
        }
    }
    return minver;
}


void prims(int** edges,int n){
    bool* vis=new bool[n];
    int* parent=new int[n];
    int* weight=new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n-1;i++){
        int minv=getminvertex(vis,weight,n);
        vis[minv]=true;
        for(int j=0;j<n;j++){
            if(edges[minv][j]!=0 && !vis[j]){
                if(weight[j]>edges[minv][j]){
                    weight[j]=edges[minv][j];
                    parent[j]=minv;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
                cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
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
    prims(edges,n);
    return 0;

}