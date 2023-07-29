#include<bits/stdc++.h>
using namespace std;



void kadane(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi=a[0];
    int sum=0;
    int st=0,end=0,ind=0;
    for(int i=0;i<n;i++){
        if(sum==0){
            ind=i;
        }
        sum+=a[i];
        if(sum>maxi){
            maxi=sum;
            st=ind;
            end=i;
        }

        if(sum<0){
            sum=0;      
              }
    }

    cout<<"sum"<<maxi<<" "<<"ind: "<<st<<" "<<end<<endl;
    
  




    return;

}

void p1285B(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    int asum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        asum+=a[i];
    }
    
    int maxi1=a[0],sum=0;
       for(int i=0;i<n-1;i++){
           sum+=a[i];
           maxi1=max(maxi1,sum);
           if(sum<0){
               sum=0;
           }
       }

        sum=0;
        int maxi2=a[1];
         for(int i=1;i<n;i++){
           sum+=a[i];
           maxi2=max(maxi2,sum);
           if(sum<0){
               sum=0;
           }
       }
       
       int s=max(maxi1,maxi2);
    if(s>=asum){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }


    
  




    return;

}

//balance parenthesis


int maxlength(vector<int> &arr,int n){
    int maxi=0;
    stack<int> st;
    st.push(0);
    for(int i=1;i<=n;i++){
        if(arr[i]>0)st.push(i);
        else{
            int ind=st.top();
            st.pop();
            if(arr[ind]==-arr[i]){
                maxi=max(maxi,i-st.top());
            }
            else{
                st.push(i);
            }

        }
    }
    return maxi;
}





int main(){
    int t;
    cin>>t;
    while(t--){

    p1285B();
    }
    
   return 0;
}