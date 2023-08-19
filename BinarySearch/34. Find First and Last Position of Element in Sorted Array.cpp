 int findfirst(vector<int>& nums, int k){
        int low=0,high=nums.size()-1;
        int n=nums.size();
        
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>k){
                high=mid-1;
            }
            else if(nums[mid]<k){
                low=mid+1;

            }
            else{

             if(mid==0 || nums[mid-1]!=nums[mid]){
                return mid;
            }
            else{
                high=mid-1;
            }
            }
            


        }
        return -1;

    }
    int findlast(vector<int>& nums, int k){
        int low=0,high=nums.size()-1;
        int n=nums.size();
        
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>k){
                high=mid-1;
            }
            else if(nums[mid]<k){
                low=mid+1;

            }
            else{

             if(mid==n-1 || nums[mid]!=nums[mid+1]){
                return mid;
            }
            else{
                low=mid+1;
            }
            }
            


        }
        return -1;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findfirst(nums,target);
        int last=findlast(nums,target);
        return {first,last};
    }