#include<bits/stdc++.h>
using namespace std;


int lps(string s){
    int maxi=0;
   int  n=s.length();
   for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]) {
            int currl=r-l+1;
            maxi=max(currl,maxi);
            l--;
            r++;

        }
          l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]) {
            int currl=r-l+1;
            maxi=max(currl,maxi);
            l--;
            r++;

        }
   } 
   return maxi;

}
int main(){
    string s;
    cin>>s;
    cout<<lps(s)<<endl;
    return 0;
}