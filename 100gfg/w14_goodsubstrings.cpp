#include<bits/stdc++.h>
using namespace std;
#define int long long


void goodSubstrings(){
    string s,goodbad;
    cin>>s >> goodbad;
    int k;
    cin>>k;

    set<int> st;
    int n=s.length();
    for(int i=0;i<n;i++){
        string sub="";
        int pr=1;
         int hash=0;
         int cntbad=0;
        for(int j=i;j<n;j++){
            sub+=s[j];
            if(goodbad[s[j]-'a']=='0')cntbad++;
            if(cntbad>k)break;

            hash=(hash+((s[j]-'a'+1)*pr));
            pr=(pr*31);
            st.insert(hash);

        }
        
    }
    cout<<st.size()<<endl;
}


int32_t main(){
    
    goodSubstrings();
    return 0;

}