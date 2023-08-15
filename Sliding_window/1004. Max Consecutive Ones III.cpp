 
 
 int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int maxi=INT_MIN;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            if(nums[j]==0)cnt++;
            if(cnt<=k){
                maxi=max(maxi,j-i+1);
                j++;
                continue;
            }

            else if(cnt>k){
                while(cnt>k){
                    if(nums[i]==0)cnt--;
                    i++;
                }
                maxi=max(maxi,j-i+1);
                j++;

            }
        }
        return maxi;


    }