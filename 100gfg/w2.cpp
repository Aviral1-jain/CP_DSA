#include<bits/stdc++.h>
using namespace std;


vector<int> sieve(1000005,1);
vector<int> vis(1000005,1);
void csieve(){
    int n=1000000;
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==1){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }
    for(int k=0;k<=20;k++){
        if(sieve[k])cout<<k<<" ";
    }
    return;


}
void fsieve(){
    int n=1000000;
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==1){
            for(int j=i*i;j<=n;j+=i){
                if(sieve[j]==1){

                vis[i]++;
                sieve[j]=0;
                }
            }
        }
    }
    for(int k=0;k<=20;k++){
        if(sieve[k])cout<<k<<" ";
    }
    cout<<endl;
    cout<<vis[2]<<" "<<vis[11];
    return;


}
vector<int> gsieve(1000005);
void gcsieve(){
    int n=1000000;
    for(int i=1;i<=n;i++){
        gsieve[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(gsieve[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(sieve[j]==j){

                
                gsieve[j]=i;
                }
            }
        }
    }
    for(int k=0;k<=20;k++){
        if(sieve[k])cout<<k<<" ";
    }
    cout<<endl;
    cout<<vis[2]<<" "<<vis[11];
    return;


}



long long power(int base,int n,int mod){
    long long ans=1;
    while(n!=0){
        if(n%2){
            n=n-1;
            ans=(ans*base)%mod;
        }
        else{
            n=n/2;
            base=(base*base)%mod;
        }
    }
    return ans;
}

void solvediv(){
    int a=6;
    int b=7;
    int mod=1e9+7;
    int c=(b*power(a,mod-2,mod))%mod;
    cout<<c<<" ";
    return;
}


void solve1314B(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
    int peaks=0;
    for(int i=1;i<k-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            peaks++;
        }
    }

    int maxpeaks=peaks;
    int ind=0;
    int l=0,r=k-1;
    while(r<=n-2){
        if(arr[r]>arr[r-1] && arr[r]>arr[r+1]){
            peaks++;
        }
        r++;
        l++;

        if(arr[l]>arr[l-1] && arr[l]>arr[l+1]){
            peaks--;
        }
        if(peaks>maxpeaks){

        maxpeaks=peaks;
        ind=l;
        }
    }

cout<<maxpeaks+1<<" "<<ind+1<<endl;

  return;
}


void solvesmallestk(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
    int maxi=0;
    int ans=maxi+1;
    int low=1,high=maxi+1;
    while(low<=high){
       int mid=(low+high)/2;
        int s=0;
        for(int i=0;i<n;i++){
            s+=arr[i]/mid;
        }
        if(s<=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<" ";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int t;
    cin>>t;
    while(t--){
    //    solve1314B();
        fsieve();
        

        
        
    }
    return 0;
}