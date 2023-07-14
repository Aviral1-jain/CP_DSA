    

#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/search-pattern0205/1
vector<int> getlps(string p){
    int len=p.length();
    vector<int> lps(len);
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


    void kmpsearch(string t,string p, vector<int> &ans){

    int tlen=t.length();
    int plen=p.length();
    int i=0,j=0;
    vector<int> lps=getlps(p);
    while(i<tlen && j<plen){
        if(t[i]==p[j]){
            i++;
            j++;
            if(j==plen){
             //   cout<<i-plen<<" ";
             ans.push_back(i-plen+1);
                j=lps[j-1];
            }
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

        
        
}

        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> ans;
            kmpsearch(txt,pat,ans);
            return ans;
            
        }


