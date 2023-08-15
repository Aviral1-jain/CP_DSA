   vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        int n=firstList.size();
        int m=secondList.size();
        vector<vector<int>> ans;
        while(i<n && j<m){
            int csp=max(firstList[i][0],secondList[j][0]);
            int cep=min(firstList[i][1],secondList[j][1]);
            if(csp<=cep){
                ans.push_back({csp,cep});


            
            }
             if(firstList[i][1]<secondList[j][1]){
                i++;

            }
            else{
                j++;

            }
            


        }
        return ans;
        
    }