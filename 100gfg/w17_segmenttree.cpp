#include <iostream>
using namespace std;
#define int long long
//https://ide.geeksforgeeks.org/TZhHETXZWW

int a[100004]; 
int seg[4*100004]; 
void build(int ind, int low, int high) {
    if(low == high) {
        seg[ind] = a[low]; 
        return; 
    }
    int mid = (low + high) >> 1;
     
    build(2*ind+1, low, mid); 
    build(2*ind+2, mid+1, high); 
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]); 
}
void update(int ind, int low, int high, int i, int val) {
    if(low == high) {
        seg[ind] = val;
        a[i] = val; 
        return; 
    }
    int mid = (low + high) >> 1;
    
    // either you go left or you go right
    if(i<=mid) {
        update(2*ind+1, low, mid, i, val); 
    }
    else {
        update(2*ind+2, mid+1, high, i, val); 
    }
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]); 
}

int minRange(int ind, int low, int high, int l, int r) {
    // complete overlap 
    // l low high r
    if(low>=l && high<=r) return seg[ind]; 
    
    // non overlap 
    // low high l r   or l r low high
    if(l > high || low > r) {
        return INT_MAX; 
    }
     int mid = (low + high) >> 1;
    // partial overlap
    int left = minRange(2*ind+1, low, mid, l, r); 
    int right = minRange(2*ind+2, mid+1, high, l ,r); 
    return min(left, right); 
}

void segmentTree() {
    int n;
    cin >> n;
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }
    
    build(0, 0, n-1); 
    
    int q;
    cin>>q;
    while(q--) {
        int l, r;
        cin >> l >> r; 
        cout << minRange(0, 0, n-1, l, r) << endl; 
    }
    
}

int main(){
    segmentTree();
    return 0;
}