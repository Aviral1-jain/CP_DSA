 vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        unordered_map<char,int> mp;
        for(auto x:p)mp[x]++;
        int k=mp.size();
        int n=s.length();
        vector<int> ans;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                k--;
            }

            }
            
             if((j-i+1)==p.length()){
                if(k==0){
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1)k++;

                }
                i++;

                
            }
                j++;
            


        }
        return ans;
    }