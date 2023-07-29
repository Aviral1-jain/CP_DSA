#include<bits/stdc++.h>

using namespace std;
#define int long long

//https://codeforces.com/problemset/problem/510/C


bool cycledetectionDG(int node,int par){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){

        if(cycledetectionDG(it,node)==true)return true;
        else if(pathvis[it]==1)return true;
        }
    }
      pathvis[node]=0;
    return false;
}
vector<int> adj[26];
void foxandNames(){
    int n;
    cin>>n;
    vector<string> vec;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }
    for(int i=0;i<n-1;i++){
        string s1=vec[i];
        string s2=vec[i+1];
        for(int j=0;j<s1.size();j++){
            //s1="rajiv" s2="raj"
            if(j>=s2.size()){
                cout<<"Impossible"<<endl;
                return;
            }
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int> vis(26,0);
    for(int i=0;i<=25;i++){
        if(!vis[i]){
            flag= flag | cycledetectionDG(i,0);
        }

    }
    if(flag){
        cout<<"Impossible"<<endl;
        return;
    }
    //print the topo sort
    stack<char> st;
    vector<int> vis1(26,0);

    void dfs(int node){
        vis1[node]=1;
        
        for(auto x:adj[node]){
            if(!vis1[x]){
                dfs(x);
            }
            
        }
        st.push(node+'a');
        return ;
        
        
    }
    
	 for(int i=0;i<=25;i++){
	        if(!vis1[i]){
	            dfs(i);
	        }
	}
	 //   vector<int> ans;
	    while(!st.empty()){
	     //   ans.push_back(st.top());
         cout<<st.top()<<" ";
        st.pop();
	    }
	    return ;







}

int32_t main(){
foxandNames();
   
return 0;

}