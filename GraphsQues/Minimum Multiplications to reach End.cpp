 #include <bits/stdc++.h> 
using namespace std;
//https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
 
 public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(100000,1e9);
        dist[start]=0;
        queue<pair<int,int>> q;
        q.push({0,start});
        
        while(!q.empty()){
            int steps=q.front().first;
            int val=q.front().second;
            q.pop();
            if(val==end)return steps;
            for(auto it:arr){
                int temp=(val*it)%(int)1e5;
                if(1+steps<dist[temp]){
                    dist[temp]=1+steps;
                    q.push({dist[temp],temp});
                }
            }
            
        }
        return -1;
        
        
    }