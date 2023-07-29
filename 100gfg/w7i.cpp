#include<bits/stdc++.h>
using namespace std;


void mim(){
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //apply power set
    vector<int> arr1,arr2;
    for(int i=0;i<n/2;i++){
        arr1.push_back(a[i]);

    }
    for(int i=n/2;i<n;i++){
      arr2.push_back(a[i]);

    }
    int n1=arr1.size();
    int n2=arr2.size();

    //apply power set
    vector<int> vec;
    for(int num=0;num<(1<<n1);num++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                sum+=arr1[i];
            }
        }
        vec.push_back(sum);

    }
    map<int,int> mpp;
    for(int num=0;num<(1<<n2);num++){
        int sum=0;
        for(int i=0;i<n2;i++){
            if(num&(1<<i)){
                sum+=arr2[i];
            }
        }
        mpp[sum]++;

    }

    int cnt=0;
    for(int i=0;i<vec.size();i++){
        cnt+=mpp[s-vec[i]];
    }
    cout<<cnt<<endl;


}

void largestalt(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi=1;
    int cnt=1;
    bool flag=true;
    int diff=1;
    for(int i=1;i<n;i++){
       
        if(a[i]-a[i-1]==diff){
            cnt++;
            maxi=max(maxi,cnt);
            diff=-diff;

        }
        else{
            cnt=1;
            diff=1;
           

         
        }
    }

cout<<maxi<<endl;


}
void mim1(){
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //apply power set
    vector<int> arr1,arr2;
    for(int i=0;i<n/2;i++){
        arr1.push_back(a[i]);

    }
    for(int i=n/2;i<n;i++){
      arr2.push_back(a[i]);

    }
    int n1=arr1.size();
    int n2=arr2.size();

    //apply power set
    vector<int> vec1;
    for(int num=0;num<(1<<n1);num++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                sum+=arr1[i];
            }
        }
        vec1.push_back(sum);

    }
    vector<int> vec2;
    for(int num=0;num<(1<<n2);num++){
        int sum=0;
        for(int i=0;i<n2;i++){
            if(num&(1<<i)){
                sum+=arr2[i];
            }
        }
        vec2.push_back(sum);

    }
    sort(vec2.begin(),vec2.end());

    int cnt=0;
    for(auto it:vec1){
      cnt+=upper_bound(vec2.begin(),vec2.end(),s-it)-vec2.begin();
      
    }
    cout<<cnt<<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    largestalt();

    return 0;
}