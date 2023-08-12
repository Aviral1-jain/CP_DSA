int withsumk(vector<int>& nums, int goal){
        int i=0,j=0;
        int sum=0;
        int n=nums.size();
        int ans=0;

        while(j<n){
            sum+=nums[j];
            while(sum>goal && i<=j){
                sum-=nums[i];
                i++;
              

            }

            ans+=j-i+1;
            j++;
            

        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return withsumk(nums,goal)- withsumk(nums,goal-1);

    }