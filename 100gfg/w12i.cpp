#include<bits/stdc++.h>

using namespace std;
#define int long long
vector<int> subtree(100005);
vector<int> level(100005);
vector<int> adj[100004];
vector<int> parent[100004];

void p1336Alinovaandkingdom(int node,int par,int lev){

    level[node]=lev;
    parent[node]=par;
    int sum=0;
    for(auto it:adj[node]){
        if(it!=par){
            p1336Alinovaandkingdom(it,node,lev+1);
            sum+=subtree[it];
        }
    }
    subtree[node]=1+sum;


}

void csesQ1(){

    //
    dfs(1,0);
    //find the kth parent of any node
    while(q--){
        int k,node;
        cin>>node>>k;
        int cnt=0;
        while(k){
            if(k&1){
                node=parent[node][cnt];

            }
            cnt++;
            k=k>>1;
        }

    }
    cout<<node<<endl;

}
//https://codeforces.com/problemset/problem/1328/E

void treeQueries(){
    dfs(1);
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        vector<int> nodes;
        int deepest=1;
        for(int i=0;i<num;i++){
            int x;
            cin>>x;
            nodes.push_back(x);
            if(level[x]>level[deepest])deepest=x;
        }

        //figure out if every node lies on the path or at a distance of 1
        int fl=1;
        for(int i=0;i<num;i++){
            int lc=lcs(deepest,node[i]);
            if(lc!=node[i]){
                int dist=dis(lc,node[i]);
                if(dist>1){
                    fl=0;
                    break;
                }
            }
        }
        if(fl==0){
            cout<<"NO"<<endl;
        }
        else{
             cout<<"YES"<<endl;
        }
    }
}


int32_t main(){

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

   
    p1336Alinovaandkingdom(1,0,1);
    vector<int> ans;
    

    for(int i=1;i<=n;i++){
        ans.push_back(level[i]-subtree[i]);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    int sum=0;
    int i=0;
    while(k--){
        sum+=ans[i];
        i++;
    }
    cout<<sum<<endl;
    return 0;


}