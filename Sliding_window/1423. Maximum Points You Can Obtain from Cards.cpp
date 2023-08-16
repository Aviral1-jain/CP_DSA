 int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int maxi=0;
        int i;
        int n=cardPoints.size();
        for( i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxi=max(maxi,sum);
        int j=n-1;
        i--;
        while(i>=0){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            maxi=max(maxi,sum);
            j--;i--;
            

        }
       // maxi=max(maxi,sum);
        return maxi;

    }