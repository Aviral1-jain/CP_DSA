#include<bits/stdc++.h>
using namespace std;



int main(){
 int n,k; cin>>n>>k;
    string s;
    char c = 'A';
    while(c<='Z')
    {
        int cnt=0;
        while(cnt<n)
        {
            s.push_back(c);
            cnt++;
        }
        c++;
    }    
    cout<<s[k-1]<<endl;

    return 0;
}
