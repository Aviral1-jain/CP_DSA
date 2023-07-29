#include<bits/stdc++.h>
using namespace std;


int d,k;
int func(int ind,int flag,int cnt,vector<int> &num){
    if(ind==num.size()){
        if(cnt==k)return 1;
        else return 0;
    }
    int limit=num[ind];
    if(flag==1){
        limit=9;
    }

    int count=0;
    for(int digit=0;digit<=limit;digit++){
        if(flag==1){
            if(digit==d){
                count+=func(ind+1,flag,cnt+1,num);
            }
            else count+=func(ind+1,flag,cnt,num);
        }
        else if(flag==0){
            if(digit==d){
                if(digit<num[ind])count+=func(ind+1,1,cnt+1,num);
                else count+=func(ind+1,0,cnt+1,num);
            }
            else{
                if(digit<num[ind])count+=func(ind+1,1,cnt,num);
                else count+=func(ind+1,0,cnt,num);
            }

        }
    }
    return count;
}


vector<int> ctv(int n){
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    return num;
}

void digitdp(){
    int l,r,d,k;
    cin>>l>>r>>d>>k;
    vector<int> num=ctv(r);
    int right=func(0,0,0,num);
    num=ctv(l-1);
    int left=func(0,0,0,num);
    cout<<right-left<<endl;




    return;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    digitdp();
   return 0;
}