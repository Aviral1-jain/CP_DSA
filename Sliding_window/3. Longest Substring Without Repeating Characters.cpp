 int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.length();
        if(n==0)return 0;
        int maxi=INT_MIN;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                maxi=max(maxi,j-i+1);
                j++;
                continue;
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                maxi=max(maxi,j-i+1);

                j++;

            }


        }
        return maxi;
    }