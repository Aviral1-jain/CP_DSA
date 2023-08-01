#include<bits/stdc++.h>
using namespace std;
//weighted job_scheduling
struct job{
    int st,fin,pro;
};

bool compare(struct job a,struct job b){
    return a.fin<b.fin;
}

int max_pro(struct job arr[],int n){
    sort(arr,arr+n,compare);
    int* dp=new int[n];
    dp[0]=arr[0].pro;
    for(int i=1;i<n;i++){
        int incl=arr[i].pro;
        int lncon=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j].fin<=arr[i].st){
                lncon=j;
                break;
            }
        }
        if(lncon!=-1){
            incl+=dp[lncon];
        }
        dp[i]=max(incl,dp[i-1]);

    }
    int ans=dp[n-1];
    delete[] dp;
    return ans;
}

int main(){

int W=70;
job arr[]={{2,5,50},{1,2,20},{6,9,70},{2,50,400}};
cout<<"maximum pro is:"<<max_pro(arr,4);
return 0;

}

//https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
struct Job{
        int start,finish,profit;
    };

    static bool compare(struct Job a,struct Job b){
        return a.finish<b.finish;
    }



    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> v;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});

        }
        sort(v.begin(),v.end(),compare);
        vector<int> dp(n);
        dp[0]=v[0].profit;
        for(int i=1;i<n;i++){
            int including=v[i].profit;
            int lnconflict=-1;

            for(int j=i-1;j>=0;j--){
                if(v[j].finish<=v[i].start){
                   lnconflict=j; 
                   break;
                }
            }
            if(lnconflict!=-1){
                including+=dp[lnconflict];
            }
            dp[i]=max(including,dp[i-1]);


        }
        return dp[n-1];


    }
