#include<bits/stdc++.h>
using namespace std;
#define int long long



void p1285B(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    int asum=0;
    for(int i=0;i<n;i++){
        
        cin>>a[i];
    }
    for(auto x:a){

        asum+=x;
    }
    
    int maxi1=a[0],sum=0;
       for(int i=0;i<n-1;i++){
           sum+=a[i];
           maxi1=max(maxi1,sum);
           if(sum<0){
               sum=0;
           }
       }

        sum=0;
        int maxi2=a[1];
         for(int i=1;i<n;i++){
           sum+=a[i];
           maxi2=max(maxi2,sum);
           if(sum<0){
               sum=0;
           }
       }
       
       int s=max(maxi1,maxi2);
    if(s>=asum){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }


    
  




    return;

}

//next greater elemnt

void nextgrtele(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    stack<int> st;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=a[i]){
            st.pop();
        }
        int ele=st.empty()?-1:st.top();
        ans.push_back(ele);
        st.push(a[i]);
        
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return;



}

//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/

void littleshino(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    stack<int> st;
    int cnt=0;
   
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<=a[i]){
            cnt++;
            st.pop();
        }
        if(!st.empty())cnt++;
        st.push(a[i]);
        
    }
    
    cout<<cnt<<endl;
    return 0;



}
//no of islands
//https://leetcode.com/problems/number-of-islands/description/

    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({r,c});
     
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
            int newr=i+dr[k];
            int newc=j+dc[k];
            if(newr>=0 && newr<n && newc>=0 && newc<m &&  grid[newr][newc]=='1' && !vis[newr][newc]){
                vis[newr][newc]=1;
                q.push({newr,newc});
                
            }
            }

        }
            return;
        }
        

    

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
      
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    vis[i][j]=1;
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }

        }
        return ans;

    }
    


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        littleshino();
       // nextgrtele();
 //   p1285B();
    }
    
   return 0;
}