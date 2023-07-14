#include<bits/stdc++.h>
using namespace std;
int main(){
//  string txt="abceabefabcd";
//  string pat="abcd";
 string txt="AABAACAADAABAABA";
 string pat="AABA";
  int m=pat.length();
  int n=txt.length();
 int h=1,q=11,d=10;
 for(int i=1;i<=m-1;i++){
    h=(h*d)%q;
 }
 int p=0,t=0;
 for(int i=0;i<m;i++){
    p=(p*d+pat[i])%q;
    t=(t*d+txt[i])%q;
 }
//  cout<<p<<" "<<t;
 for(int i=0;i<=n-m;i++){
    if(p==t){
        bool flag=true;
        for(int j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<i<<" ";
        }
    }
    if(i<n-m){
        t=((d*(t-txt[i]*h))+txt[i+m])%q;
        if(t<0){
            t=t+q;
        }
    }
 }
    return 0;
}