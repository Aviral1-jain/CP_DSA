#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[]={-8, 2, 3, -6, 10};
    int k=2;
    int i=0,j=0;
    //int mini=INT_MAX;
    vector<int> v,ans;
 //   int ans=0;
   

    while(j<n){
        if(arr[j]<0) ans.push_back(arr[j]);
       
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
         //   mini=min(mini,ans);
           // ans-=arr[i];
           v.push_back(ans.empty()==true?0:ans[0]);
           if(!ans.empty() && ans[0]==arr[i]){
            ans.erase(ans.begin());
           }
            i++;
            j++;

        }

    }

    for(auto x:v)cout<<x<<" ";
    return 0;



}