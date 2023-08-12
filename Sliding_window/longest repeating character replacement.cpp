//https://leetcode.com/problems/longest-repeating-character-replacement/description/

int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxi=0,ans=INT_MIN;
        map<int,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            if((j-i+1)-maxi>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }