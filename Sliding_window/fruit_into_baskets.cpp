int totalFruit(vector<int>& s) {
    
        int i=0,j=0;
        int n=s.size();
        if(n==0)return 0;
        int maxi=INT_MIN;
        unordered_map<int,int> mp;
        while(j<n){
            mp[s[j]]++;
            // if(mp.size()<2){
            //     j++;
            //     continue;
            // }
            if(mp.size()<=2){
                maxi=max(maxi,j-i+1);
                j++;
                continue;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                if(mp.size()<=2){
                maxi=max(maxi,j-i+1);
                j++;
                }
            }
               

            }


        
        return maxi;
    }

