#include <bits/stdc++.h> 

int maximumProduct(vector<int> &nums, int n)
{
	int res=INT_MIN;
	int curr=1;
	// that maximum product subarray present a starting
	for(int i=0; i<n; i++){
		curr *= nums[i];
		res = max(res,curr);
		if(curr==0) curr=1;
	}

	// that maximum product subarray occurs at ending
	curr=1;
	for(int i=n-1; i>=0; i--){
		curr *= nums[i];
		res = max(res,curr);
		if(curr==0) curr=1;
	}
	return res;
}
