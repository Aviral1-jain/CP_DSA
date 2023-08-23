string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        string ans="";
        int n=s.length();
        pair<int,char> block={-1,'A'};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            ans+=curr.second;
            curr.first--;
            if(block.first>0){
                pq.push(block);
            }
            block=curr;
        }
        if(ans.length()==n)return ans;
        return "";
        


    }