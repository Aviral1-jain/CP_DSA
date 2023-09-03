#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_920336
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int> ans;
    unordered_map<int,int> mp;
     int i=0,j=0;
    // for(;i<k;i++){
    //     mp[arr[i]]++;

    // }
  //  ans.push_back(mp.size());
    while(j<arr.size()){
        mp[arr[j]]++;
        if(j-i+1<k){
            j++;
            continue;
        }
        else if(j-i+1==k){
            ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++;
            j++;
        }



    }
    return ans;


	
}