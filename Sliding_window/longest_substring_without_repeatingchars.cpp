int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int maxi=1;
        if(s.length()==0)return 0;
        unordered_map<char,int> mp;
        while(j<s.length()){
        if(mp.find(s[j])!=mp.end())i=max(mp[s[j]]+1,i);
            mp[s[j]]=j;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;

    }
/////

int longestSubstrDistinctChars (string s)
{
    // your code here
    map<char,int> mp;
    int n=s.length();
    int i=0,j=0;
    int maxi=1;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==(j-i+1)){
            maxi=max(maxi,j-i+1);
            j++;
            continue;
        }
        if(mp.size()<(j-i+1)){
            while(mp.size()<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                    
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
            
            
        }
    }
    return maxi;
    
}

