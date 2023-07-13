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

bool kmpsearch(string t,string p){

    int tlen=t.length();
    int plen=p.length();
    int i=0,j=0;
    int* lps=getlps(p);
    while(i<tlen && j<plen){
        if(t[i]==p[j]){
            i++;
            j++;
        }
        else{
           if(j!=0){
                j=lps[j-1];
           }
           else{
            i++;
           }
        }
    }

        if(j==plen){
            return true;
        }
        else return false;
        
}

int main(){
    string str="abcxabcdabcdabcy";
    string p="abcdabcx";
  //  cin>>s>>p;
    // int* gem=getlps(p);
    // for(int i=0;i<p.length();i++){
    //     cout<<gem[i]<<" ";
    // }
    cout<<kmpsearch(str,p)<<endl;
    return 0;
}



