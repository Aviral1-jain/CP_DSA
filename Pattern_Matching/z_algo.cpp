#include<bits/stdc++.h>
using namespace std;

void buildz(int* z,string str){
    int l=0,r=0;
    int n=str.length();
    for(int i=1;i<n;i++){
        if(i>r){

        l=i;
        r=i;
        while(r<n && str[r-l]==str[r]){
            r++;
        }
        z[i]=r-l;
        r--;
        }
        else{
            int k=i-l;
            if(z[k]<=r-i){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n && str[r-l]==str[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }

    }
}



void searchstring(string t,string p){
    string str=p+"$"+t;
    int n=str.length();
    int* z=new int[n]();
    buildz(z,str);
    for(int i=0;i<n;i++){
        if(z[i]==p.length()){
            cout<<i-p.length()-1<<endl;
        }
    }

}





int main(){
    string str="abcdsafbcdfasbcda";
    string p="bcd";
    searchstring(str,p);
    return 0;
}