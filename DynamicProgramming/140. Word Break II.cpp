void path(int ind,int n,string s,string temp,unordered_map<string,int> &mp,vector<string> &ans){
        if(ind==n){
            int m=temp.length();
            temp[m-1]='\0';
            ans.push_back(temp);
            return;

        }
        for(int i=ind;i<n;i++){
            string k=s.substr(ind,i-ind+1);
            if(mp.find(k)!=mp.end()){
                k+=" ";
                path(i+1,n,s,temp+k,mp,ans);
            //    path(i+1,n,s,temp,mp,ans);
                

            }
        }
        return;
    }



    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        vector<string> ans;
        string temp="";
         path(0,n,s,temp,mp,ans);
         return ans;



    }