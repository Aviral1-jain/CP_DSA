#include<bits/stdc++.h>
using namespace std;

int main(){


    string pat,txt;
    cin>>pat>>txt;
    map<char,int> mp;
	    for(auto x:pat)mp[x]++;
	    int cnt=mp.size();
	    int i=0,j=0;
	    int ans=0;
	    int k=pat.length();
	    while(j<txt.length()){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)cnt--;
	        }
	        if(j-i+1<k){
	           	//mp[txt[j]]--;
	           	j++;
	           	
	        }
	        else if(j-i+1==k){
	            if(cnt==0){
	                ans++;
	                
	            }
	            if(mp.find(txt[i])!=mp.end()){
	                if(mp[txt[i]]==0)cnt++;
	                
	                mp[txt[i]]++;
	                
	            }
	            i++;
	            j++;
	        }

	        
	    }
	    cout<< ans;
        return 0;

}