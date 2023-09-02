#include <bits/stdc++.h> 

int atmost(vector<int>& arr, int n, int b){
	int i=0,j=0;
	map<int,int> mp;
	int ans=0;
	while(j<n){
	mp[arr[j]]++;
	while(i<=j && mp.size()>b){
		mp[arr[i]]--;
		if(mp[arr[i]]==0)mp.erase(arr[i]);
		i++;
	}
	ans+=(j-i+1);
	j++;


	}
	return ans;
}

int goodSubarrays(vector<int>& arr, int n, int b)
{
	// Write your code here.
	return atmost(arr,n,b)-atmost(arr,n,b-1);
}
