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
                if(sieve[j]==1){
                sieve[j]=0;

                }
            }
        }
    }
  
    return;


}

void segmentsieve(){
    csieve();
    int l,r;
    cin>>l>>r;
    //collect all primes till sqrt(r)
    vector<int> primes;
    for(int i=2;i*i<=r;i++){
        if(sieve[i]==1){
            primes.push_back(i);
        }
    }

   // create a dummy array
   vector<int> dummy(r-l+1,1);
   
    for(auto pr:primes){
        int firstmultiple=(l/pr)*pr;
        if(l%pr)firstmultiple+=pr;

        for(int j=max(firstmultiple,pr*pr);j<=r;j+=pr){
            dummy[j-l]=0;
        }

    }
    //iterate and count primes
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(dummy[i-l]==1){
       //     cout<<i<<endl;
            cnt++;
        }
    }

    cout<<cnt<<endl;



}
//max len of subarray with 0 sum

int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
       
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                ans=max(ans,i+1);
            }
            
            else if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }
            else mp[sum]=i; 
        }
        return ans;
        
    }

    void solve1907B(){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums) cin>>x;
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=nums[j];
                }
                else{
                    sum-=nums[j];
                }
            }
            if(sum%360==0){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
                return;
        

    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve1907B();
    
    // int t;
    // cin>>t;
 //   while(t--){
        
 //       segmentsieve();

        
        
  //  }
    return 0;
}
