   int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x:tasks)mp[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }

        int time=0;
        while(!pq.empty()){
            if(pq.top().first==1){
                time+=pq.size();
                break;
            }
            vector<pair<int,char>> temp;
            temp.push_back(pq.top());
            pq.pop();
            time+=1;
            for(int i=0;i<n;i++){
                if(!pq.empty()){
                    auto it=pq.top();
                    temp.push_back(it);
                    pq.pop();
                 
                    
                }
                time++;


            }

            for(auto x:temp){
                if(x.first>1)pq.push({x.first-1,x.second});
            }


          
        }
        return time;

    }