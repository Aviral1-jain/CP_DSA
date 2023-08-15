 long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long int,long long int> mp;
        int time=0;
        long long int tillmaxtime=0;
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])==mp.end()){
             //   time+=1;
                tillmaxtime++;
                mp[tasks[i]]=tillmaxtime;
               // tillmaxtime=i+1;
            }
            else{
                if(tillmaxtime-mp[tasks[i]]>space){
                    tillmaxtime++;
                    mp[tasks[i]]=tillmaxtime;
                    continue;

                }
                else{

                tillmaxtime=mp[tasks[i]]+space+1LL;
                mp[tasks[i]]=tillmaxtime;
                }


            }
        }
        return tillmaxtime;
    }