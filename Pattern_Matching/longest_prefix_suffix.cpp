#include<bits/stdc++.h>
using namespace std;

int* getlps(string p){
    int len=p.length();
    int* lps=new int[len];
    lps[0]=0;
    int i=1,j=0;
    while(i<len){
        if(p[j]==p[i]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){

            j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}



int main(){
    string s,p;
    cin>>s>>p;
    int* gem=getlps(p);
    for(int i=0;i<p.length();i++){
        cout<<gem[i]<<" ";
    }
    return 0;
}



