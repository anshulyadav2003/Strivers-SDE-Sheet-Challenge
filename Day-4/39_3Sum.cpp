#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int> nums, int n, int k) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for(int i=0; i<n; i++)
	{
		int a = nums[i];
		int target = k-a;
		
		// twosum CODE for sorted array
		int s=i+1, e=n-1;
		while(s<e)
		{
			int sum = nums[s]+nums[e];
			if(sum==target){
				vector<int> v;
				v.push_back(a);
				v.push_back(nums[s]);
				v.push_back(nums[e]);
				ans.push_back(v);
				while(s<e && nums[s]==nums[s+1])    s++;
				while(s<e && nums[e]==nums[e-1])    e--;
				s++; e--;
			}
			else if(sum<target){
				s++;
			}
			else{
				e--;
			}
		}
		while(i+1<n && nums[i+1]==nums[i])  i++;
	}
	
	return ans;
}