#include<bits/stdc++.h>
using namespace std;

struct item{
    int val,wgt;
};

bool compare(struct item a,struct item b){
    double val1=((double)a.val)/(a.wgt);
    double val2=((double)b.val)/(b.wgt);

    return val1>val2;
}

double knap_sack(struct item arr[],int W,int n){
    sort(arr,arr+n,compare);
    int currW=0;
    double fvalue=0;
    for(int i=0;i<n;i++){
        if(currW+arr[i].wgt<=W){
            currW+=arr[i].wgt;
            fvalue+=arr[i].val;
        }
        else{
            int rwgt=W-currW;
            fvalue+=arr[i].val*((double)rwgt/arr[i].wgt);
            break;
        }
    }
    return fvalue;
}

int main(){

int W=70;
item arr[]={{60,20},{70,15},{80,40}};
cout<<"maximum value is:"<<knap_sack(arr,W,3);
return 0;

}


//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
   public:
    //Function to get the maximum total value in the knapsack.
    
    static bool compare(pair<double,double> &a,pair<double,double> &b){
        double val1=(double)(a.first/a.second);
        double val2=(double)(b.first/b.second);
        return val1>val2;
        
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,double>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({(double)arr[i].value,(double)arr[i].weight});
            
        }
        sort(vp.begin(),vp.end(),compare);
        int currw=0;
        double fvalue=0;
        
        for(int i=0;i<n;i++){
            if(currw+vp[i].second<=W){
                fvalue+=vp[i].first;
                currw+=vp[i].second;
                
            }
             else{
            int rwgt=W-currw;
            fvalue+=vp[i].first*((double)rwgt/vp[i].second);
            break;
                }
            
        }
        return fvalue;
        
        
        
    }
