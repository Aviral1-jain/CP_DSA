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
int countDistinctSubstrings(string s){
    set<int> st;
    for(int i=0;i<n;i++){
        string sub="";
        int pr=1;
         int hash=0;
        for(int j=i;j<n;j++){
            sub+=s[j];
            hash=(hash+((s[j]-'a'+1)*pr)%mod)%mod;
            pr=(pr*31)%mod;
            st.insert(hash);

        }
        
    }
    return st.size();
}
int prefixHash[100005];

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

int computeSubstringHash(int l,int r){
    int hash=(prefixHash[r]);
    if(l>0){
        hash=(hash-(prefix[l-1])+mod)%mod;
    }
    //divide
    hash=hash*power(power(31,l,mod),mod-2,mod);
    return hash;
}

void querySubstring(){
    string s;
    cin>>s;
    int n=s.size();
    int pr=1;
    int hash=0;
        for(int i=0;i<n;i++){
           
            hash=(hash+((s[i]-'a'+1)*pr)%mod)%mod;
            prefixHash[i]=hash;
            pr=(pr*31)%mod;
            

        }

        int q;
        cin>>q;
        while(q--){
            int i1,j1,i2,j2;
            cin>>i1>>j1>>i2>>j2;

            int hash1=computeSubstringHash(i1,j1);
            int hash2=computeSubstringHash(i2,j2);
            if(hash1==hash2)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

}



int32_t main(){
    
    int rollhash=computehash(s);
    return 0;

}