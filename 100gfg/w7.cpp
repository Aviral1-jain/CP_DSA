#include<bits/stdc++.h>
using namespace std;
#define int long long


void merge(int low,int mid,int high,int a[]){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(a[left]);
            left++;
    }
    while(right<=high){
         temp.push_back(a[right]);
            right++;
    }
      for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
      }

    return;
}


void mergeSort(int low,int high,int a[],int n){
    if(low>=high)return;
    int mid=(low+high)>>1;
    mergeSort(low,mid,a,n);
    mergeSort(mid+1,high,a,n);
    merge(low,mid,high,a);
    return;
}

void testcases(){
    int a[]={1,2,0,4,3,2};
    int n=6;
    mergeSort(0,n-1,a,n);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
     
    return;
   
}


int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    testcases();


   
    return 0;
}
// inversion counts
    long long cnt=0;
    
    void merge(long long low,long long mid,long long high,long long a[]){
    vector<long long> temp;
    long long left=low;
    long long right=mid+1;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
         temp.push_back(a[left]);
            left++;
    }
    while(right<=high){
         temp.push_back(a[right]);
            right++;
    }
      for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
      }

    return;
}


void mergeSort(long long low,long long high,long long a[],long long n){
    if(low>=high)return;
    long long mid=(low+high)>>1;
    mergeSort(low,mid,a,n);
    mergeSort(mid+1,high,a,n);
    merge(low,mid,high,a);
    return;
}
    long long inversionCount(long long a[], long long n)
    {
        // Your Code Here
        mergeSort(0,n-1,a,n);
        return cnt;
    }