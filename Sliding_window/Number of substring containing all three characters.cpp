int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int n=s.length();
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<3){
                j++;
                continue;

            }
            else if(mp.size()==3){
             //   ans++;
                while(mp.size()==3){
                    ans+=(n-j);
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;

                }
                j++;
            }
            
        }
        return ans;
    }