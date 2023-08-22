   long long cnt=0;
     void merge(long long arr[], long long low, long long mid, long long high)
    {
         // Your code here
         vector<long long> temp;
         long long left=low;
         long long right=mid+1;
         while(left<=mid && right<=high){
             if(arr[left]<=arr[right]){
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 cnt+=(mid-left+1);
                 right++;
             }
         }
         
         while(left<=mid){
            temp.push_back(arr[left]);
                 left++;
         }
         while(right<=high){
           temp.push_back(arr[right]);
                 right++;
         }
         
         for(int i=low;i<=high;i++){
             arr[i]=temp[i-low];
         }
    }
    
    void mergeSort(long long arr[], long long low, long long high)
    {
        //code here
        if(low>=high)return;
        long long mid=(low+high)>>1;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
        return;
        
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        mergeSort(arr,0,n-1);
        return cnt;
    }