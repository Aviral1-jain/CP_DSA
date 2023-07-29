#include <bits/stdc++.h>

using namespace std;
#define int long long
 
//https://codeforces.com/problemset/problem/380/C
struct node
{
    int open,close,full;
};

node seg[4*100005]; 
string s;

void build(int ind, int low, int high) {
    if(low == high) {
       node temp;
       temp.open=temp.close=temp.full=0;
       if(s[low] == '(')temp.open=1;
       else temp.close=1;

       seg[ind]=temp;


         
        return; 
    }
    int mid = (low + high) >> 1;
     
    build(2*ind+1, low, mid); 
    build(2*ind+2, mid+1, high); 
    seg[ind].full = seg[2*ind+1].full+ seg[2*ind+2].full+min(seg[2*ind+1].open, seg[2*ind+2].close); 
    seg[ind].open = seg[2*ind+1].open+ seg[2*ind+2].open-min(seg[2*ind+1].open, seg[2*ind+2].close); 
    seg[ind].close = seg[2*ind+1].close+ seg[2*ind+2].close-min(seg[2*ind+1].open, seg[2*ind+2].close); 

}

node minRange(int ind, int low, int high, int l, int r) {
    // complete overlap 
    // l low high r
    if(low>=l && high<=r) return seg[ind]; 
    
    // non overlap 
    // low high l r   or l r low high
    if(l > high || low > r) {
        node temp;
       temp.open=temp.close=temp.full=0;
       return temp;
      
    }
     int mid = (low + high) >> 1;
    // partial overlap
    node left = minRange(2*ind+1, low, mid, l, r); 
    node right = minRange(2*ind+2, mid+1, high, l ,r); 
     node ans;
     ans.full = left.full+ right.full+min(left.open, right.close); 
    ans.open = left.open+ right.open-min(left.open, right.close); 
    ans.close = left.close+ right.close-min(left.open, right.close);
    return ans;
}

void serejaAndBrackets(){
    cin>>s;
    int q;
    cin>>q;
    build(0,0,s.size()-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        node ans=minRange(0,0,s.size()-1,l,r);
        cout<< ans.full*2 <<endl;

    }
}

int32_t main(){
    serejaAndBrackets();
    return 0;
}


