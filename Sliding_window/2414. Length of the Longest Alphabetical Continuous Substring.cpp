  int longestContinuousSubstring(string s) {
        int i=0,j=0;
        int n=s.length();
        int ans=INT_MIN;
        while(j<n){
            if(s[j]-s[i]==(j-i)){
                ans=max(j-i+1,ans);
                j++;
            }
            else if((j-i)!=s[j]-s[i]){
                while(s[j]-s[i]!=(j-i)){
                    i++;

                }
                ans=max(j-i+1,ans);
                j++;

            }
            

        }
        return ans;
    }