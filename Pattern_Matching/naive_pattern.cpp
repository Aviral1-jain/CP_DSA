#include<bits/stdc++.h>
using namespace std;
int main(){
 string txt="acabcd";
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
  }
    return 0;
}
//gfg11