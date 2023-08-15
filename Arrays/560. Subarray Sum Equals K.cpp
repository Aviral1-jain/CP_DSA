 int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        unordered_map<int,int> mp;
        int ans=0;
        mp[0]=1;

        for(int i=0;i<nums.size();i++){
             presum+=nums[i];
            if(mp.find(presum-k)!=mp.end()){
                ans+=mp[presum-k];

            }
           
                mp[presum]+=1;
            
        }
        return ans;
    }