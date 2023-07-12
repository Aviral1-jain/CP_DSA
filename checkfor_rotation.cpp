#include<bits/stdc++.h>
using namespace std;
int main(){
 string txt="abab";
 string pat="abba";
if(txt.length()!=pat.length())cout<<"no";
else if((txt+txt).find(pat)!=string::npos){
cout<<"yes";
}
else{
  cout<<"no";  
}




     return 0;
}