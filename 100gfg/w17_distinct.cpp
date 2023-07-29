#include <bits/stdc++.h>

using namespace std;
#define int long long

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/



bitset<5001> seg[4*100005];
bitset<5001> seg1[4*100005];
int a[100004]; 
int b[100004]; 

void build(int ind, int low, int high) {
    if(low == high) {
        seg[ind].set(a[low]); 
        return; 
    }
    int mid = (low + high) >> 1;
     
    build(2*ind+1, low, mid); 
    build(2*ind+2, mid+1, high); 
    seg[ind] = seg[2*ind+1] | seg[2*ind+2]; 
}


bitset<5001> minRange(int ind, int low, int high, int l, int r) {
    // complete overlap 
    // l low high r
    if(low>=l && high<=r) return seg[ind]; 
    
    // non overlap 
    // low high l r   or l r low high
    if(l > high || low > r) {
        bitset<5001> temp;
        return temp; 
    }
     int mid = (low + high) >> 1;
    // partial overlap
    bitset<5001> left = minRange(2*ind+1, low, mid, l, r); 
    bitset<5001> right = minRange(2*ind+2, mid+1, high, l ,r); 
    return left | right; 
}

void build1(int ind, int low, int high) {
    if(low == high) {
        seg1[ind].set(b[low]); 
        return; 
    }
    int mid = (low + high) >> 1;
     
    build1(2*ind+1, low, mid); 
    build1(2*ind+2, mid+1, high); 
    seg1[ind] = seg1[2*ind+1] | seg1[2*ind+2]; 
}


bitset<5001> minRange1(int ind, int low, int high, int l, int r) {
    // complete overlap 
    // l low high r
    if(low>=l && high<=r) return seg1[ind]; 
    
    // non overlap 
    // low high l r   or l r low high
    if(l > high || low > r) {
        bitset<5001> temp;
        return temp; 
    }
     int mid = (low + high) >> 1;
    // partial overlap
    bitset<5001> left = minRange1(2*ind+1, low, mid, l, r); 
    bitset<5001> right = minRange1(2*ind+2, mid+1, high, l ,r); 
    return left | right; 
}




void dist(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    build(0,0,n-1);
    build1(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r,l1,r1;
        cin>>l>>r>>l1>>r1;
        l--;r--;
        l1--;r1--;
        bitset<5001> ans1 = minRange(0,0,n-1,l,r); 
        bitset<5001> ans2 = minRange1(0,0,n-1, l1 ,r1); 
       bitset<5001> final=ans1 | ans2;
       cout<< final.count()<<endl;
        // cout<< ans1.count()<<endl;
        // cout<<ans2.count() <<endl;

    }
    return;
}


int32_t main(){


    dist();
    return 0;
}


