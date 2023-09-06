  #include<bits/stdc++.h>
  using namespace std;
  
  int path(int i,string s,unordered_map<string,bool> &mp,vector<int> &dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        string curr="";
        int res=s.size();
        for(int j=i;j<s.size();j++){
            curr.push_back(s[j]);
            int excnt=curr.size();
            if(mp[curr]){
                excnt=0;
            }
            excnt+=path(j+1,s,mp,dp);
            res=min(res,excnt);
        }
        return dp[i]=res;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,bool> mp;
        for(auto it:dictionary){
            mp[it]=true;
        }
        vector<int> dp(s.size(),-1);
        return path(0,s,mp,dp);
    }