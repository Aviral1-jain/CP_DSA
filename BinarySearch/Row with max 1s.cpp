int lowerBound(vector<int> arr, int n, int x) {
  // Write your code here
  int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
            
        }
        return ans==-1?n:ans;
  
}

int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
{
    //    Write your code here.
    int cnt=INT_MIN;
    int ans=-1;
    for(int i=0;i<n;i++){
        
        int res=m-lowerBound(arr[i],m,1);
        if(res>cnt){
            cnt=res;
            ans=i;

        }



        
    }
    return ans;

}