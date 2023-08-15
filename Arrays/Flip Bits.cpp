 int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ind=0,st=-1,end=-1;
        
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)cnt++;
            else cnt--;
            if(cnt>maxi){
                // st=ind;
                // end=i;
                maxi=cnt;
            }
            if(cnt<0){
                cnt=0;
               // ind=i+1;
            }
        }
       // cout<<st<<" "<<end;
      //  int k=0;
        for(int i=0;i<n;i++){
            maxi+=a[i];
        }
        
        return maxi;
    }
    