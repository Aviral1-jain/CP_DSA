vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int i=0;
        while(i<k){
            pq.push({nums[i],i});
            i++;
        }

        for(i=k;i<nums.size();i++){
            ans.push_back(pq.top().first);
            while(!pq.empty() && pq.top().second<=(i-k)){
                pq.pop();
            }
            pq.push({nums[i],i});
        }

        
        ans.push_back(pq.top().first);

        return ans;

    }