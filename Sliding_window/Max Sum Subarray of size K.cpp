    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long maxi=INT_MIN;
        int i=0,j=0;
        long sum=0;
        
        while(j<n){
        sum+=arr[j];
        if(j-i+1<k){
            j++;
            continue;
        }
        else if(j-i+1==k){
            maxi=max(maxi,sum);
            sum-=arr[i];
            i++;
            j++;
        }
        
        
        }
        return maxi;
    }