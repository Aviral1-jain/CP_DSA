#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src,dest,weight;
};

bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
}

int getparent(int v,int* parent){
    if(parent[v]==v){
        return v;
    }
    return getparent(parent[v],parent);
}

edge* kruskals(edge* edges,int n,int e){

    sort(edges,edges+e,compare);
    edge* output=new edge[n-1];
    int* parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int cnt=0;
    int i=0;
    while(cnt<(n-1)){
        edge curr=edges[i];
        int srcpar=getparent(curr.src,parent);
        int despar=getparent(curr.dest,parent);
        if(srcpar!=despar){
            output[cnt]=curr;
            cnt++;
            parent[srcpar]=despar;
        }
        i+=1;
    }
return output;

}

int main(){
    int n,e;
    cin>>n>>e;

    edge* edges=new edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }

    edge* output=kruskals(edges,n,e);

    for(int i=0;i<n-1;i++){
        if(output[i].src<output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
             cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }





    return 0;
}