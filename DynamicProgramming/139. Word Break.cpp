int path(int i,int n,string s,vector<int> &dp,unordered_map<string,int> &mp){
        if(i==n){
            return true;

        }
        if(dp[i]!=-1)return dp[i];
        for(int ind=i;ind<n;ind++){
            string temp=s.substr(i,ind-i+1);
            if(mp.find(temp)!=mp.end()){
                if(path(ind+1,n,s,dp,mp))return dp[i]=true;
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        vector<int> dp(n,-1);
        return path(0,n,s,dp,mp);

        
    }

    //tabulation
     bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int ind=i;ind<n;ind++){
            string temp=s.substr(i,ind-i+1);
            if(mp.find(temp)!=mp.end()){
                if(dp[ind+1]) dp[i]=true;
            }
        }
        

        }
        return dp[0];

        
    }
    