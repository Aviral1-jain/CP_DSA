#include<bits/stdc++.h>
using namespace std;

bool ismatch(string s,string p){
    int n=s.length();
    int m=p.length();
    for(int i=0;i<=n-m;i++){
        bool isfound=true;
        for(int j=0;j<m;j++){
            if(s[i+j]!=p[j]){
                isfound=false;
                break;
            }
        }
        if(isfound==true)return true;
    }
    return false;
}

//O(n*m)

int main(){
    string s,p;
    cin>>s>>p;
    cout<<ismatch(s,p)<<endl;
    return 0;
}



