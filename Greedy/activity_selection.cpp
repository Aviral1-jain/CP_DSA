
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1



static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int prev=0;
        int res=1;
        for(int i=1;i<n;i++){
            if(vp[i].first>vp[prev].second){
                res++;
                prev=i;
                
                
            }
            
        }
        
        return res;
        
        
    }