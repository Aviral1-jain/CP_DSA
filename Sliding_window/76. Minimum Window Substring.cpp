    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x:t)mp[x]++;
        int cnt=mp.size();
        int i=0,j=0;
        int mini=INT_MAX;
        int n=s.length();
        string ans="";
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)cnt--;
            }
            if(cnt==0){
                if(j-i+1<mini){
                mini=j-i+1;
                ans=s.substr(i,j-i+1);
                }

                
                while(i<=j && cnt==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){

                       if(j-i+1<mini){
                        mini=j-i+1;
                        ans=s.substr(i,j-i+1);
                } 
                cnt++;
                    }
                }
                    
                i++;
                    
                }
            }
                j++;


        }
        return ans;
    }