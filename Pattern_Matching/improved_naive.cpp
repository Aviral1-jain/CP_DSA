#include<bits/stdc++.h>
using namespace std;
//for distinct elemnts
//gfg12
int main(){
 string txt="abceabefabcd";
 string pat="abcd";
  int m=pat.length();
  int n=txt.length();
  for(int i=0;i<=n-m;i++){
    int j;
    for(j=0;j<m;j++){
        if(pat[j]!=txt[i+j])
        break;
    }
    if(j==m){
        cout<<i<<" ";
    }
    if(j==0){
        i++;
    }
    else{
        i=i+j;
    }
  }
    return 0;
}