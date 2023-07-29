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

int32_t main(){
    
    int rollhash=computehash(s);
    return 0;

}