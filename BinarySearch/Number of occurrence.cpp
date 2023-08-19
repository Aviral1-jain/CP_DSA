	int findfirst(int nums[], int k,int n){
        int low=0,high=n-1;
     //   int n=nums.size();
        
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
    int findlast(int nums[], int k,int n){
        int low=0,high=n-1;
    ;
        
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
    
	int count(int nums[], int n, int x) {
	    // code here
	       int first=findfirst(nums,x,n);
        int last=findlast(nums,x,n);
        if(last==-1 && first==-1)return 0;
        return last-first+1;
	}