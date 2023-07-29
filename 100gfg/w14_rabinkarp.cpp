#include<bits/stdc++.h>
using namespace std;
#define int long long

int computehash(string s){
    int pr=1;
    int mod=1e9+7;
    int hash=0;
    for(auto it:s){
        hash=(hash+((s[i]-'a'+1)*pr)%mod)%mod;
        pr=(pr*31)%mod;

    }
    return hash;
}

int power(int base,int n,int mod){

    int ans=1;
    while(n){
        if(n%2){
            n=n-1;
            ans=(ans*base)%mod;
        }
        else{
            base=(base*base);
            n=n/2;
        }
    }
    return ans;


}

void rabinkarp(string s,string pat){
    int pathash=computehash(pat);
    int n1=pat.size();
    int n2=s.size();
    int hash=computehash(s(0,n1));
    int left=0,right=n1-1;
    int cnt=0;
    if(hash==pathash)cnt++;
    while(right<n-1){
        right++;
        hash=(hash+((s[right]-'a'+1)*power(31,right))%mod)%mod;
        hash=(hash-((s[left]-'a'+1)*power(31,left))%mod)%mod;
        left++;
        pathash=(pathash*31)%mod;
        if(pathash==hash){
            cnt++;
            cout<<left<<" "<<endl;
        }

    }


    
}


int32_t main(){
    
    goodSubstrings();
    return 0;

}