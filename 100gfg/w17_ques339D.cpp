#include <iostream>
using namespace std;

int a[100004]; 
int seg[4*100004]; 
int el,n;
void build(int ind, int low, int high,int flag) {
    if(low == high) {
        seg[ind] = a[low]; 
        return; 
    }
    int mid = (low + high) >> 1;
     
    build(2*ind, low, mid,!flag); 
    build(2*ind+1, mid+1, high,!flag); 
    if(n%2){
        if(flag%2){
             seg[ind] = (seg[2*ind] ^seg[2*ind+1]);
        }
        else{
            seg[ind] = (seg[2*ind] |seg[2*ind+1]);
        }
    }
    else{
        if(flag%2){
             seg[ind] = (seg[2*ind] |seg[2*ind+1]);
        }
        else{
            seg[ind] = (seg[2*ind] ^seg[2*ind+1]);
        }
    }
    
}
void update(int ind, int low, int high, int i, int val,int flag) {
    if(low == high) {
        seg[ind] = val;
        a[i] = val; 
        return; 
    }
    int mid = (low + high) >> 1;
    
    // either you go left or you go right
    if(i<=mid) {
        update(2*ind, low, mid, i, val,!flag); 
    }
    else {
        update(2*ind+1, mid+1, high, i, val,!flag); 
    }
        if(n%2){
        if(flag%2){
             seg[ind] = (seg[2*ind] ^seg[2*ind+1]);
        }
        else{
            seg[ind] = (seg[2*ind] |seg[2*ind+1]);
        }
    }
    else{
        if(flag%2){
             seg[ind] = (seg[2*ind] |seg[2*ind+1]);
        }
        else{
            seg[ind] = (seg[2*ind] ^seg[2*ind+1]);
        }
    }
     
}



//https://codeforces.com/problemset/problem/339/D/

void xeniaAndBit(){
    int q;
    cin>>n>>q;
    el=1<<n;
  //  int a[el+1];
    for(int i=1;i<=el;i++){
        cin>>a[i];

    }

    build(1,1,el,1);
    while(q--){
        int i,val;
        cin>>i>>val;
        update(1,1,n,i,val,1);
        cout<<seg[1]<<endl;

    }
    return;
}


int main(){
    xeniaAndBit();
    return 0;
}