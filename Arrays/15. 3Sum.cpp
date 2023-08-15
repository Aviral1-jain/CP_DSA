   vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=0-nums[i];
            int l=i+1,h=n-1;
            while(l<h){
                if(nums[l]+nums[h]==temp){
                    st.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h]>temp){
                    h--;

                }
                else{
                    l++;
                }
            }
        }
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }