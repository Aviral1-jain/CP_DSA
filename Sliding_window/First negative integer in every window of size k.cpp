//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
            vector<long long> ans,vis;
            int i=0,j=0;
            while(j<n){
                
                if(arr[j]<0)vis.push_back(arr[j]);
                if(j-i+1<k){
                    j++;
                    continue;
                }
                else if(j-i+1==k){
                    int temp=vis.empty()==true?0:vis[0];
                    ans.push_back(temp);
                    if(!vis.empty() && vis[0]==arr[i]){
                        vis.erase(vis.begin());
                        
                    }
                    i++;j++;
                }
                
            }
            return ans;
            
                                                 
            
                                                 
 }