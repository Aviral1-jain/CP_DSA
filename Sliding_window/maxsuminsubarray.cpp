#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7;
    int arr[]={2,5,1,8,2,9,1};
    int k=2;
    int i=0,j=0;
    int mini=INT_MAX;
    int ans=0;
   

    while(j<n){
            ans+=arr[j];
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            mini=min(mini,ans);
            ans-=arr[i];
            i++;
            j++;

        }

    }

    cout<<mini<<" "<<endl;
    return 0;



}