#include<bits/stdc++.h>
using namespace std;
#define int long long

int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
     
        return pq.top();
    }

//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/
    void seatingarrangemnt(){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int,int>> pq;
        string str;
        cin>>str;

        //solve
        pq.push({n,-1});
        map<int,int> mp;
        for(int i=1;i<=k;i++){
            auto it=pq.top();
            pq.pop();
            int len=it.first;
            int st=-1*it.second;
            int end=st+len-1;
            int mid=(st+end)/2;
            if(len%2==0 && str[i-1]=='R'){
                mid+=1;

            }
            mp[mid]=i;
            if(mid!=st){
            pq.push({mid-st,-1*st});

            }
            if(mid!=end){
                pq.push({end-mid,-1*(mid+1)});
            }





        }

        int q;
        cin>>q;
        while(q--){
            int chair;
            cin>>chair;
            if(mp.find(chair)==mp.end()){
                cout<<-1<<endl;
            }
            else{
                cout<<mp[chair]<<endl;
            }
        }


    }

int32_t main(){
    
    seatingarrangemnt();
   return 0;
}