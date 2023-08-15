int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<int,int> mp;
    int i=0,j=0;
    int n=str.length();
    int maxi=INT_MIN;

    while(j<n){
        mp[str[j]]++;
        if(mp.size()<=k){
            maxi=max(maxi,j-i+1);
            j++;
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[str[i]]--;
                if(mp[str[i]]==0){
                    mp.erase(str[i]);
                }
                i++;
                
            }

            maxi=max(maxi,j-i+1);

            j++;
        }



    }

    return maxi;


}