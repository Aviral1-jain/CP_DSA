#include<vector>
#include<bits/stdc++.h>
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here.
	
	int maxi=0;

	unordered_map<int,int> mp;
	//mp[0]=-1;
	int n=arr.size();
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum==0){
			maxi=max(maxi,i+1);
		}

		if(mp.find(sum-0)!=mp.end()){
			maxi=max(maxi,i-mp[sum]);
		}
		else{
			mp[sum]=i;
		}
		
	}
	return maxi;
	
}