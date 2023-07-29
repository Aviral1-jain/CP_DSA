#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fact(100005);
vector<int> powerr(100005);
int mod=(int)1e9+7;


void precomputeFactorial(){
    fact[0]=1;
    int ans=1;
    for(int i=1;i<=100005;i++){
        ans=(ans*i)%mod;
        fact[i]=ans;
        powerr[i]=power(fact[i],mod-2,mod);
    }

}
int power(int base,int n,int mod){
    int ans=1;
    while(n){
        if(n%2){
            n=n-1;
            ans=(ans*base)%mod;
        }
        else{
            n=n/2;
            base=(base*base)%mod;
        }
    }
    return ans;
}


int nCr2(int n,int r){
    return (fact[n]*(powerr[r]*powerr[n-r])%mod)%mod;



}
int nCr(int n,int r){
    return (fact[n]*(power(fact[r],mod-2,mod)*power(fact[n-r],mod-2,mod))%mod)%mod;



}

int nCr1 (int n,int r){
    return fact[n]/(fact[r]*fact[n-r]);



}


void printCombos(int n,vector<int> &vec){
    if(n==0){
        for(auto x:vec)cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        vec.push_back(vec[i]);
        printCombos(n-i,vec);
        vec.pop_back();
    }
}

void picknotpick(int ind,int sum,vector<int> &ds){
    if(ind==n){
        if(sum==0){
            for(auto x:ds)cout<<x<<" ";
            cout<<endl;
        }
        return;
    }
    if(a[i]<=sum){
        ds.push_back(a[i]);
        picknotpick(ind+1,sum-a[ind],ds);
        ds.pop_back();
    }
    picknotpick(ind+1,sum,ds);

}

void printpermut(int ind,string s,vector<int> &ds){
    if(ind==n){
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(hash[i]==0){
        hash[i]=1;
        s+=str[i];
        printpermut(ind+1,s,ds);
        mpp[i]=;
        s.pop_back();

        }
      
    }
  

}





void testcases(){
    precomputeFactorial();
    int t;
    cin>>t;
    while(t--){
    int n,r;
    cin>>n>>r;
    cout<<nCr1(n,r)<<endl;
        


        
        
   }
}
//////////////
 bool issafe(int row,int col,vector<vector<int>> &vec,int n){
        int ii=row;
        int jj=col;
        
        //line 1
        while(ii>=0 && jj>=0){
            if(vec[ii][jj])return false;
            ii--;
            jj--;
        }
         ii=row;
         jj=col;
        
        //line 2
        while(jj>=0){
            if(vec[ii][jj])return false;
         
            jj--;
        }
        ii=row;
        jj=col;
        
        //line 3
        while(ii<n && jj>=0){
            if(vec[ii][jj])return false;
            ii++;
            jj--;
        }
        return true;
    }
    void printQ(int col,int n,vector<vector<int>> &ans,vector<vector<int>> &vec){
        if(col==n){
            vector<int> temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(vec[j][i])
                    temp.push_back(j+1);
                }
            }
           ans.push_back(temp); 
           return;
        }
        
        for(int row=0;row<n;row++){
            if(issafe(row,col,vec,n)){
                vec[row][col]=1;
                printQ(col+1,n,ans,vec);
                vec[row][col]=0;
            }
        }
        return;
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> vec(n,vector<int>(n,0));
        vector<vector<int>> ans;
        printQ(0,n,ans,vec);
        return ans;
        
    }
    

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testcases();

   
    return 0;
}
