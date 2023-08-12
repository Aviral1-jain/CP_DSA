int solve(char ch,string answerKey, int k){
         int i=0,j=0;
        int maxi=0,ans=INT_MIN;
        int cnt=0;
     //   unordered_map<char,int> mp;
        while(j<answerKey.length()){
          //  mp[s[j]]++;
            if(answerKey[j]==ch)cnt++;
          //  maxi=max(maxi,mp[s[j]]);
            if(cnt>k){
                if(answerKey[i]==ch)cnt--;
               // mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int path1=solve('T',answerKey,k);
        int path2=solve('F',answerKey,k);
        return max(path1,path2);
    }